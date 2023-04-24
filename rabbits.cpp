#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <windows.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "rabbits.h"
#include "util.h"
#include "grid.h"

using namespace std;
//loads rabbit coordinates from file
void LoadRabbits(int rabbitsX[],int rabbitsY[], int numRabbits)
{
    ifstream myfile;
    myfile.open("rabbits.txt", ios::in);
    if(myfile)
    {
        int x;
        for(int i=0; i<15; i++)
        {


            myfile>>rabbitsX[i];
            myfile>>rabbitsY[i];


        }
        myfile.close();

    }
    else
        cout<<"Could not open file"<<endl;
}

void MoveRabbits(int rabbitsX[],int rabbitsY[], bool stationary, int numRabbits)
{
    //iterate through all rabbits
    for(int i=0; i<numRabbits; i++)
    {
        //if a rabbit is uncaptured, move, and check coordinates in case they move out of the grid
        if(InvalidPos(rabbitsX[i], rabbitsY[i])==false)
        {
            AutonomousMove(rabbitsX[i], rabbitsY[i]);
            EdgeDetect(rabbitsX[i], rabbitsY[i]);

        }
    }
}

//generates random coordinates for rabbits or load from file
void SetRabbits(int rabbitsX[],int rabbitsY[], bool RandPositions, int numRabbits)
{
    if(RandPositions == true)
    {
        for(int i=0; i<numRabbits; i++)
        {
            rabbitsX[i] = randCoord(23,1);
            rabbitsY[i] = randCoord(23,1);
        }
    }
    else
        LoadRabbits(rabbitsX, rabbitsY, numRabbits);
}
