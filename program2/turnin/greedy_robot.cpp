#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cmath>
#include "greedy_robot.h"

Game::Game(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y) {
    this->max_distance_ = max_distance;
    this->robot_x_ = robot_x;
    this->robot_y_ = robot_y;
    this->treasure_x_ = treasure_x;
    this->treasure_y_ = treasure_y;
}

int Game::ShortestPossibleDistance() {
    return abs(this->robot_x_ - this->treasure_x_) + abs(this->robot_y_ - this->treasure_y_);
}

// might not need this
bool Game::IsRobotAtChest(int robot_x, int robot_y) const {
    if (robot_x == this->treasure_x_ && robot_y == this->treasure_y_) {
        return true;
    }

    return false;
}

bool Game::MaxDistanceBroken(const std::string &path) const {
    char last_direction = path[path.size() - 1];
    int count = 0;
    for (int i = path.size() - 1; i >=0; i--) {
        if (path[i] == last_direction) {
            count++;
        } else {
            break;
        }
    }

    if (count > this->max_distance_) {
        return false;
    }
    return true;
}

// Find all paths that go directly towards the treasure
void Game::FindPaths(int robot_x, int robot_y, std::string path, std::vector<std::string> &paths) {
    // if robot has already moved in one direction too many times, drop the path
    if (!MaxDistanceBroken(path)) {
        return;
    }

    // if robot makes it all the way, add the path
    if (IsRobotAtChest(robot_x, robot_y)) {
        paths.push_back(path);
    }

    // deal with X direction
    if (robot_x < this->treasure_x_) {
        FindPaths(robot_x + 1, robot_y, path + "E", paths);
    } else if (robot_x > this->treasure_x_) {
        FindPaths(robot_x - 1, robot_y, path + "W", paths);
    }

    // deal with Y direction
    if (robot_y < this->treasure_y_) {
        FindPaths(robot_x, robot_y + 1, path + "N", paths);
    } else if (robot_y > this->treasure_y_) {
        FindPaths(robot_x, robot_y - 1, path + "S", paths);
    }
}

void Game::PrintShortestPaths() {
    if (IsRobotAtChest(this->robot_x_, this->robot_y_)) {
        std::cout << "Already there!" << std::endl;
        return;
    }

    std::string path = "";
    std::vector<std::string> paths;
    FindPaths(this->robot_x_, this->robot_y_, path, paths);

    if (paths.size() == 0) {
        std::cout << "No paths possible under constraints! NP" << std::endl;
        return;
    }

    for (std::string str : paths) {
        std::cout << str << std::endl;
    }
    std::cout << "Number of paths: " << paths.size() << std::endl;
    std::cout << "Shortest distance: " << ShortestPossibleDistance() << std::endl;
}