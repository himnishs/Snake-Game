#ifndef SNAKE_H
#define SNAKE_H

#include <random>
#include <iostream>
using std::cout;

const int width = 20;
const int height = 20;
class Snake
{
    public:
        void Setup(bool &gameOver);
        void Draw();
        void Input();
        void Logic();

    private:
        int x;
        int y;
        int fruitX;
        int fruitY;
        int score;
        enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection direction_snake;
};
#endif