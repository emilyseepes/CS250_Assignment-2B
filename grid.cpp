#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <windows.h>
#include <math.h>


#include "grid.h"
#include "util.h"
#include "foxes.h"
#include "rabbits.h"
using namespace std;


//sets the borders for the grid
void SetGrid(char grid[25][25])
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(i==0 || i==24)
                grid[i][j]='-';//-
            else
            {
                if(j==0 || j==24)
                    grid[i][j]='|';
                else
                    cout<<' ';
            }
        }
    }
}

bool InvalidPos(int x, int y)
{
    if(x ==-1 || y ==-1)
        return true;
    else
        return false;
}

void UpdateGrid(int rabbitsX[],int rabbitsY[], int foxesX[], int foxesY[], char grid[25][25], int &score, int numRabbits, int numFoxes)
{
    //reset graphics for foxes
    for(int j=0; j< numFoxes; j++)
    {
        grid[foxesX[j]][foxesY[j]] = 'X';
    }

    //iterate through all rabbits and check if they are captured or not
    for(int i=0; i<numRabbits; i++)
    {
        if(InvalidPos(rabbitsX[i], rabbitsY[i]) == false)//only consider uncaptured rabbits
        {
            if(Capture(rabbitsX[i], rabbitsY[i], grid) == false)
            {
                grid[rabbitsX[i]][rabbitsY[i]]='o'; //not captured, set their graphic
            }

            else
            {
                //captured, set rabbits coordinate to invalid
                rabbitsX[i] = -1;
                rabbitsY[i] = -1;
                score++;    //increment score, how many rabbits have been captured
            }
        }
    }
}

void PrintMap(char grid[25][25], int score, int turns)
{
    system("CLS");

    //make sure grid edges remain intact
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(i==0 || i==24)
                grid[i][j]='-';//-
            else
            {
                if(j==0 || j==24)
                    grid[i][j]='|';
            }
        }
    }

    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
    cout<<"Score:"<<score<<endl;
    cout<<"Turns:"<<turns<<endl;
}

//initializes the grid 2D array
void GridInit(char grid[25][25])
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
            grid[i][j]=' ';
    }
}

//checks if capture occurs
//If rabbit is on an square next to the fox, or they are in the same square, capture happens
bool Capture(int x, int y, char grid[25][25]);


//since foxes move, we clear their last position
void ResetFoxes(char grid[25][25], int foxesX[], int foxesY[], int numFoxes)
{
    for(int i=0; i<numFoxes; i++)
    {
        if(foxesX[i]!= -1 && foxesY[i] != -1)
            grid[foxesX[i]][foxesY[i]] = ' ';
    }
}

void ResetRabbits(char grid[25][25], int rabbitsX[], int rabbitsY[], int numRabbits)
{
    for(int i=0; i<15; i++)
    {
        if(rabbitsX[i]!= -1 && rabbitsY[i] != -1)
            grid[rabbitsX[i]][rabbitsY[i]] = ' ';
    }
}




