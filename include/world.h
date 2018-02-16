#ifndef WORLD_H
#define WORLD_H

#include "robot.h"
#include <vector>

class world
{
    public:

        world(std::vector<std::vector<char>> Map, char EmptyCh);
        ~world();
        void run();
        bool addRobot(char Name, int Row, int Col);

    private:

        void display();
        void RMRH(int i);                       // Here the robot movement request are handled
        std::vector<std::vector<char>> map_;    // 2D data structure that represents the map
        std::vector<robot*> robots;             // Vector of type robot that contains the robot instances
        char emptyCh;                           // This character represents a free space in the map
};

#endif // WORLD_H
