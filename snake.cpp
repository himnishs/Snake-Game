#include "snake.h"
#include <random>
#include <iostream>
#include "ncurses.h"
using namespace std;
void Snake::Setup(bool &gameOver)
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    gameOver = false;
    direction_snake = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = (rand() % width) + 1;
    fruitY = (rand() % height) + 1;

}
void Snake::Draw()
{
    /*
    Things to do:
    - Attempt to add a custom map
    - Make more maps (small maps, big maps, etc)
    */

    clear();
    for(int i = 0; i < width + 1; i++)
    {
        mvprintw(0,i,"-");
    }

    for(int i = 0; i < height + 2; i++)
    {
        for(int j = 0; j < width + 2; j++)
        {
            if(j == 0 || i == 21 )
            {
                mvprintw(i+1,j,"|");
            }

            if(i == y && j == x)
            {
                mvprintw(i,j,"O");
            }
            // Needs to be more randomized
            else if(i == fruitY && j == fruitX)
            {
                mvprintw(i,j,"F");
            }
            else
            {
                mvprintw(i,j,"");
            }

            if(j == width - 1)
            {
                mvprintw(i+1,j+1,"|");
            }
        }
    }

    for(int i = 0; i < width; i++)
    {
        mvprintw(22,i,"-");
    }
    mvprintw(23,0,"Score %d", score);
    refresh();
}
/*
int kbhit()
{
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 2;
    }
}
*/
void Snake::Input()
{
    /*
        TODO:
        Have a feature for the user to change the speed of snake.

    */
    keypad(stdscr, TRUE); // Ignores 
    halfdelay(2); // can use to adjust speed of snake
    int c = getch();
    switch (c)
        {
            case 'w':
                direction_snake = UP;
                break;
            case 'a':
                direction_snake = LEFT;
                break;
            case 's':
                direction_snake = DOWN;
                break;
            case 'd':
                direction_snake = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
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

    //Checks if the snake is out of bounds
    if(x >= width || x <= 0 || y >= height || y <= 0)
    {
        gameOver = true;
    }

    //Checks if the snake ate the fruit
    if(x == fruitX && y == fruitY)
    {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

}

bool Snake::getOver()
{
    return gameOver;
}