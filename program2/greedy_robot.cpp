#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "greedy_robot.h"

Game::Game(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y) {
    this->max_distance_ = max_distance;
    this->robot_x_ = robot_x;
    this->robot_y_ = robot_y;
    this->treasure_x_ = treasure_x;
    this->treasure_y_ = treasure_y;
}

// might not need this
bool Game::IsRobotAtChest(int robot_x, int robot_y) const {
    if (robot_x == this->treasure_x_ && robot_y == this->treasure_y_) {
        return true;
    }

    return false;
}

// Find all paths
void Game::FindPaths(int robot_x, int robot_y, std::string path, std::vector<std::string> &paths) {
    if (IsRobotAtChest(robot_x, robot_y)) {
        paths.push_back(path);
    }

    if (robot_x < this->treasure_x_) {
        FindPaths(robot_x + 1, robot_y, path + "E", paths);
    } else if (robot_x > this->treasure_x_) {
        FindPaths(robot_x - 1, robot_y, path + "W", paths);
    }

    if (robot_y < this->treasure_y_) {
        FindPaths(robot_x, robot_y + 1, path + "N", paths);
    } else if (robot_y > this->treasure_y_) {
        FindPaths(robot_x, robot_y - 1, path + "S", paths);
    }
}

void Game::PrintShortestPaths() {
    std::string path = "";
    std::vector<std::string> paths;
    FindPaths(this->robot_x_, this->robot_y_, path, paths);

    for (std::string str : paths) {
        std::cout << str << std::endl;
    }
}