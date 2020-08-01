#ifndef SNAKE_H
#define SNAKE_H

const int width = 20;
const int height = 20;
class Snake
{
    public:
        void Setup(bool &gameOver);
        void Draw();
        void Input();
        void Logic();
        bool getOver();

    private:
        int x;
        int y;
        int fruitX;
        int fruitY;
        int score;
        enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection direction_snake;
        bool gameOver = false;
};
#endif