#ifndef ROBOT_H
#define ROBOT_H

#include <pthread.h>

class robot
{
    public:

        robot(char Name, int Row, int Col);
        ~robot();
        void Run();

        struct parameters
        {
            char name;
            int row;
            int col;
            int moveDirection;
            bool moveRequest;

        }param;

    private:

        static void *threadWorker(void *ptr);
        pthread_t thread;
};

#endif // ROBOT_H
