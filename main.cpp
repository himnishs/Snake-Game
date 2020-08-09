 
#include "snake.h"
#include "ncurses.h"
int main()
{
    /*
    Goals for Today:
    - Add a second player
    - Connect to AWS
    - Custom Speed(Done)

    */
    Snake snake;
    bool gameOver_1 = snake.getOver();
    int input;
    int speed = 3;
    snake.CustomSetup(speed);
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