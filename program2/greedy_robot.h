#pragma once

#include <string>
#include <vector>

class Game {
    public:
        Game(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
        void PrintShortestPaths();
        void PrintGameStatistics() const;
    
    private:
        int max_distance_;

        int robot_x_;
        int robot_y_;

        int treasure_x_;
        int treasure_y_;

        bool IsRobotAtChest(int robot_x, int robot_y) const;
        void FindPaths(int robot_x, int robot_y, std::string path, std::vector<std::string> &paths);
        
        // todo: implement filter paths
        std::vector<std::string> FilterPaths(const std::vector<std::string> &paths);
};