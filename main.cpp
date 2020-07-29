#include "snake.h"
int main()
{
    Snake snake;
    bool gameOver = false;
    snake.Setup(gameOver);

    while(!gameOver)
    {
        snake.Draw();
        //snake.Input();
        //snake.Logic();
        // Sleep function
    }

    
}