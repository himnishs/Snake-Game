#include "snake.h"

void Snake::Setup(bool &gameOver)
{
    gameOver = false;
    direction_snake = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

}
void Snake::Draw()
{
    /*
    Things to do:
    - Attempt to add a custom map
    */

    system("clear"); // use system("cls") if using windows
    for(int i = 0; i < width + 1; i++)
    {
        std::cout<< "-";
    }
    std::cout<<'\n';


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0 )
            {
                std::cout<< "|";
            }
            else
            {
                std::cout<<" ";
            }

            if(j == width - 1)
            {
                std::cout<<"|";
            }
        }
        std::cout<<'\n';
    }
    for(int i = 0; i < width + 1; i++)
    {
        std::cout<< "-";
    }
    std::cout<<'\n';
}
void Snake::Input()
{

}
void Snake::Logic()
{

}