#include "snake.h"
#include "ncurses.h"
int main()
{
    Snake snake;
    bool gameOver_1 = snake.getOver();
    int input;
    int speed = 3;
    int map_size = 0;
    snake.CustomSetup(speed, map_size);
    snake.Setup(gameOver_1);
    snake.Draw();

    while(!gameOver_1)
    {
        gameOver_1 = snake.getOver();
        snake.Draw();
        snake.Input(speed);
        snake.Logic();
    }
    getch();
    endwin();
}