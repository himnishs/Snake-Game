#include "snake.h"
#include "ncurses.h"
int main()
{
    Snake snake;
    bool gameOver_1 = snake.getOver();
    snake.Setup(gameOver_1);

    while(!gameOver_1)
    {
        gameOver_1 = snake.getOver();
        refresh();
        snake.Draw();
        snake.Input();
        snake.Logic();
        // Sleep function
    }

    
}