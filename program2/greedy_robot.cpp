#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "greedy_robot.h"

Game::Game(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y) {
    this->max_distance_ = max_distance;

    // Create entities
    Entity robot {
        .x_ = robot_x,
        .y_ = robot_y
    };

    Entity treasure {
        .x_ = treasure_x,
        .y_ = treasure_y
    };

    this->robot_ = robot;
    this->treasure_ = treasure;
}

void Game::PrintGameStatistics() const {
    std::cout << "Treasure game! (max distance: " << this->max_distance_ << ")\n";
    std::cout << "Robot position: (" << this->robot_.x_ << ", " << this->robot_.y_ << ")\n";
    std::cout << "Treasure position: (" << this->treasure_.x_ << ", " << this->treasure_.y_ << ")\n";
}

// no map bounds so movement functions will always succeed
inline void Game::MoveRobotNorth(Entity &robot) {
    robot.y_++;
}

inline void Game::MoveRobotEast(Entity &robot) {
    robot.x_++;
}

inline void Game::MoveRobotSouth(Entity &robot) {
    robot.y_--;
}

inline void Game::MoveRobotWest(Entity &robot) {
    robot.x_--;
}

// might not need this
bool Game::IsRobotAtChest(const Entity &robot) const {
    if (robot.x_ == this->treasure_.x_ && robot.y_ == this->treasure_.y_) {
        return true;
    }

    return false;
}


void Game::FindPaths(Entity robot, std::string &path, std::vector<std::string> &paths) {
    std::cout << "Some random branch path string: " << path << std::endl;
    if (IsRobotAtChest(robot)) {
        paths.push_back(path);
    }

    if (robot.x_ < this->treasure_.x_) {
        this->MoveRobotEast(robot);
        std::string new_path(path);
        FindPaths(robot, new_path.append("E"), paths);
    } else if (robot.x_ > this->treasure_.x_) {
        this->MoveRobotWest(robot);
        std::string new_path(path);
        FindPaths(robot, new_path.append("W"), paths);
    }

    if (robot.y_ < this->treasure_.y_) {
        this->MoveRobotNorth(robot);
        std::string new_path(path);
        FindPaths(robot, new_path.append("N"), paths);
    } else if (robot.x_ > this->treasure_.x_) {
        this->MoveRobotSouth(robot);
        std::string new_path(path);
        FindPaths(robot, new_path.append("S"), paths);
    }
}

void Game::PrintShortestPaths() {
    std::string path = "";
    std::vector<std::string> paths;
    FindPaths(this->robot_, path, paths);

    for (std::string str : paths) {
        std::cout << str << std::endl;
    }
}