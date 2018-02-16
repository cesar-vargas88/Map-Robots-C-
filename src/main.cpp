#include "world.h"

int main(int argc, char** argv)
{
    std::vector<std::vector<char>> Map(10, std::vector<char>(10));

    Map = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#'},
            {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
            {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    world w(Map, ' ');
    w.addRobot('A', 1, 1);
    w.addRobot('B', 8, 8);
    w.addRobot('C', 5, 5);
    w.addRobot('D', 1, 8);
    w.addRobot('E', 8, 2);
    w.addRobot('F', 1, 5);
    w.run();

    return 0;
}