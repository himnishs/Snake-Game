#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
const int width = 20;
const int height = 20;
class Snake
{
    public:
        void Setup(bool &gameOver);
        void Draw();
        void Input();
        void Logic(int speed);
        bool getOver();
        void changeLeft(int &value, int speed);
        void changeRight(int &value, int speed);
        void changeDown(int &value, int speed);
        void changeUp(int &value, int speed);
        
    private:
        int x;
        int y;
        int fruitX;
        int fruitY;
        int score = 0;
        enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection direction_snake;
        bool gameOver = false;
        std::vector<int> tailX = std::vector<int>(100);
        std::vector<int> tailY = std::vector<int>(100);
        int nTail;
        bool print = false;
};
#endif