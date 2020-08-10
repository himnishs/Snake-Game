#include "snake.h"
#include <random>
#include <iostream>
#include "ncurses.h"
using namespace std;

static int height;
static int width;
void Snake::CustomSetup(int &speed, int &map_size)
{
    std::cout<<"Welcome to the Snake Game! "<<'\n';
    std::cout<<"How fast do you want the game to be? (1-- Slow, 2-- Medium, 3-- Fast)"<<'\n';
    std::cin>>speed;
    std::cout<<"How big would you like the map to be? (1-- Small, 2-- Medium, 3-- Large)"<<'\n';
    std::cin>>map_size;

    switch(map_size)
    {
        case 1:
            height = rand() % 20 + 10;
            width = height;
            break;
        case 2:
            height = rand() % 30 + 20;
            width = height;
            break;
        case 3:
            height = rand() % 40 + 30;
            width = height;
            break;
        default:
            height = 20;
            width = 20;
    }
    return;
}

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
    score = 0;
}

void Snake::Draw()
{
    clear();
    for(int i = 0; i < width+2; i++)
    {
        mvprintw(0,i,"-");
    }
    for(int i = 0; i < height+2; i++)
    {
        for(int j = 0; j < width+2; j++)
        {

            if (i == 0 || i == width+1)
            {
                mvprintw(i, j, "-");
            }
            else if (j == 0 || j == width+1)
            {
                mvprintw(i, j, "-");
            }
            else if (i == y && j == x)
            {
                mvprintw(i, j, "O");
            }
            else if(i == fruitY && j == fruitX)
            {
                mvprintw(i, j, "F");
            }
            else
            {
              for(int k = 0; k < nTail; k++)
              {
                if (tailX[k] == j && tailY[k] == i)
                {
                    mvprintw(i, j, "o");
                }
              }
            }      
        }
    }
    mvprintw(width+3, 0, "Score %d", score);
    refresh();
}

void Snake::Input(int speed)
{
    keypad(stdscr, TRUE);
    switch(speed)
    {
        case 1:
            halfdelay(3);
            break;
        case 2:
            halfdelay(2);
            break;
        case 3:
            halfdelay(1);
            break;
        default:
            halfdelay(2);
            break;
    }
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

void Snake::Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for (int i = 1; i < nTail; i++)
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

    if(x > width || x < 1 || y < 1 || y > height)
    {
        gameOver = true;
    }

    if(x == fruitX && y == fruitY)
    {
        score++;
        fruitX = (rand() % width)+1;
        fruitY = (rand() % height)+1;
        nTail++;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
}

bool Snake::getOver()
{
    return gameOver;
}