#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
class Snake
{
    public:
        void CustomSetup(int &speed, int &map_size);
        void Setup(bool &gameOver);
        void Draw();
        void Input(int speed);
        void Logic();
        bool getOver();
    private:
        int x;
        int y;
        int fruitX;
        int fruitY;
        int score = 0;
        int nTail;
        bool gameOver = false;
        enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
        eDirection direction_snake;
        std::vector<int> tailX = std::vector<int>(100);
        std::vector<int> tailY = std::vector<int>(100);
};
#endif