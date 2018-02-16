#include "robot.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <iostream>

robot::robot(char Name, int Row, int Col)
{
    param.name  = Name;
    param.row   = Row;
    param.col   = Col;

    param.moveDirection = 0;
    param.moveRequest   = false;

    srand (Row*time(NULL));
}

robot::~robot()
{
    pthread_exit(NULL);
}

void robot::Run()
{
    pthread_create(&thread, NULL, threadWorker, &param);
}

void *robot::threadWorker(void* ptr)
{
    parameters *Param = (parameters*)ptr;

    while(true)
    {
        if(!Param->moveRequest)
        {
            /*(rand() % 4) + 1 Generates a random number from 1 to 4 that indicates the robot the direction to move
            1 Up
            2 Down
            3 Left
            4 Righ*/
            Param->moveDirection = (rand() % 4) + 1;
            // This flag will change to false when the world receives my move request and process it
            Param->moveRequest  = true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
