#include <iostream>
#include <string>
#include <sstream>
#include "greedy_robot.h"

// char to int
int ProcessArgument(int index, char *argv[]) {
    std::istringstream iss(argv[index]);
    int val;
    if (iss >> val) { // conversion successful
        return val;
    } else {
        std::cerr << "Cannot be converted to integer!" << std::endl;
        return -1;
    }
}

int main(int argc, char *argv[]) {
    int max_distance = ProcessArgument(1, argv);
    int robot_x = ProcessArgument(2, argv);
    int robot_y = ProcessArgument(3, argv);
    int treasure_x = ProcessArgument(4, argv);
    int treasure_y = ProcessArgument(5, argv);

    Game game(max_distance, robot_x, robot_y, treasure_x, treasure_y);
    game.PrintShortestPaths();

    return 0;
}