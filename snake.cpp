#include "snake.h"
#include <random>
#include <iostream>
#include "ncurses.h"
using namespace std;
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

            if(i == y && j == x)
            {
                std::cout<<"O";
            }
            else if(i == fruitY && j == fruitX)
            {
                std::cout<<"F";
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
    refresh();
}
void Snake::Input()
{
int ch;
initscr();
cbreak();
noecho();
scrollok(stdscr, TRUE);
nodelay(stdscr, TRUE);

for (;;)
{
    if ((ch = getch()) == ERR)
    {
        gameOver = true;
    }
    else
    {
        switch(ch)
        { 
            case 'a':
                ungetch(ch);
                direction_snake = LEFT;
                break;
            case 'd':
                ungetch(ch);
                direction_snake = RIGHT;
                break;
            case 'w':
                ungetch(ch);
                direction_snake = UP;
                break;
            case 's':
                ungetch(ch);
                direction_snake = DOWN;
                break;
            case 'q':
                ungetch(ch);
                direction_snake = UP;
                gameOver = true;
                break;
        }
    }
}    
}

void Snake::Logic()
{
    switch(direction_snake)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
}

bool Snake::getOver()
{
    return gameOver;
}