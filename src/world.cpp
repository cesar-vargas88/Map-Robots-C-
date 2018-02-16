#include "world.h"
#include <iostream>
#include <thread>
#include <chrono>

world::world(std::vector<std::vector<char>> Map, char EmptyCh)
{
    emptyCh = EmptyCh;
    map_    = Map;      // Pass the Map argument by reference
}

world::~world()
{
    // Deallocate the block of memory assigned to robot instances
    while(robots.size() > 0)
    {
        delete robots.back();
        robots.pop_back();
    }
}

void world::run()
{
    // here all the robots are run
    for(unsigned int i = 0; i < robots.size(); i++)
        robots.at(i)->Run();

    while(true)
    {
        display();

        for(unsigned int i = 0; i < robots.size(); i++)
            RMRH(i);

        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

bool world::addRobot(char Name, int Row, int Col)
{
    //Adds a new robot to the robot vector if the position that the robot wants to occupy is available
    if(map_[Row][Col] == emptyCh)
    {
        robot  *bot = new robot(Name, Row, Col);
        robots.push_back(bot);
        map_[Row][Col] = Name;

        return true;
    }

    return false;
}

void world::display()
{
    for(int i = 0; i < map_.size()/2; i++)
        std::cout << std::endl;

    for(int i = 0; i < map_.size(); i++)
    {
        for(int j = 0; j < map_[i].size(); j++)
            std::cout << map_[i][j] << " ";

        std::cout << std::endl;
    }
}

void world::RMRH(int i)
{
    // Verify that exist a movement request
    if(robots.at(i)->param.moveRequest)
    {
        int row = 0;
        int col = 0;

        // Depending on the moveDirection generated by the robot, estimates the new position
        switch(robots.at(i)->param.moveDirection)
        {
            case 1: // Up
                row = robots.at(i)->param.row-1;
                col = robots.at(i)->param.col;
                break;
            case 2: // Down
                row = robots.at(i)->param.row+1;
                col = robots.at(i)->param.col;
                break;
            case 3: // Left
                row = robots.at(i)->param.row;
                col = robots.at(i)->param.col-1;
                break;
            case 4: // Right
                row = robots.at(i)->param.row;
                col = robots.at(i)->param.col+1;
                break;
        }

        // Verify that the new position is not occupied or off the map
        if( row >= 0 && row < map_.size()    &&
            col >= 0 && col < map_[0].size() &&
            map_[row][col] == emptyCh)
        {
            // Update the new position of the robot on the map
            map_[robots.at(i)->param.row][robots.at(i)->param.col] = emptyCh;
            map_[row][col] = robots.at(i)->param.name;

            // Update the new robot position on the map in the robot instance
            robots.at(i)->param.row = row;
            robots.at(i)->param.col = col;
        }
        // Change the state of the flag so that the robot knows that it can request more movements
        robots.at(i)->param.moveRequest = false;
    }
}