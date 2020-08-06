#include "snake.h"
#include <random>
#include <iostream>
#include "ncurses.h"
using namespace std;
void Snake::Setup(bool &gameOver)
{
    //Ncurses setup
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
                for(int k = 0; k < nTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        mvprintw(i,j,"o");
                    }
                }
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

void Snake::Input()
{
    /*
        TODO:
        Have a feature for the user to change the speed of snake.

    */
    keypad(stdscr, TRUE);
    halfdelay(2);
    int c = getch();
    switch (c)
        {
            case 'w':
            case KEY_UP:
                direction_snake = UP;
                break;
            case 'a':
            case KEY_LEFT:
                direction_snake = LEFT;
                break;
            case 's':
            case KEY_DOWN:
                direction_snake = DOWN;
                break;
            case 'd':
            case KEY_RIGHT:
                direction_snake = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
}    

void Snake::Logic(int speed)
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X;
    int prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(direction_snake)
    {
        /*
            Controls the speed of the snake game
        */
        case LEFT:
            changeLeft(x,speed);
            //x--;
            break;
        case RIGHT:
            //x = changeRight(x,speed);
            x++;
            break;
        case UP:
            //y = changeUp(y, speed);
            y--;
            break;
        case DOWN:
            //y = changeDown(y, speed);
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
        nTail++;
    }

    for(int i = 0; i < nTail; i++)
    {
        if(tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
}

bool Snake::getOver()
{
    return gameOver;
}

void Snake::changeLeft(int &value, int speed)
{
    switch(speed)
    {
        case 1:
            value--;
            break;
        case 2:
            value -= 2;
            break;
        case 3:
            value -= 3;
            break;
            value--;
            break;
    }
}

void Snake::changeRight(int &value, int speed)
{
    switch(speed)
    {
        case 1:
            value++;
            break;
        case 2:
            value += 2;
            break;
        case 3:
            value += 3;
            break;
        default:
            value++;
            break;
    }
}

void Snake::changeDown(int &value, int speed)
{
    switch(speed)
    {
        case 1:
            value++;
            break;
        case 2:
            value += 2;
            break;
        case 3:
            value += 3;
            break;
        default:
            value++;
            break;
    }
}

void Snake::changeUp(int &value, int speed)
{
    switch(speed)
    {
        case 1:
            value--;
            break;
        case 2:
            value -= 2;
            break;
        case 3:
            value -= 3;
            break;
        default:
            value--;
            break;
    }
}
