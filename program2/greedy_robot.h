#pragma once

#include <string>

struct Entity {
    int x_;
    int y_;
};

class Game {
    public:
        Game(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
        void PrintShortestPaths();
        void PrintGameStatistics() const;
    
    private:
        Entity robot_;
        Entity treasure_;
        int max_distance_;

        // player movements. Move functions check map bounds
        bool IsPosWithinBounds(int pos) const;

        inline void MoveRobotNorth(Entity &robot);
        inline void MoveRobotEast(Entity &robot);
        inline void MoveRobotSouth(Entity &robot);
        inline void MoveRobotWest(Entity &robot);
        bool IsPlayerAtChest() const;
        bool IsRobotAtChest(const Entity &robot) const;

        void FindPaths(Entity robot, std::string &path, std::vector<std::string> &paths);
};