#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <windows.h>
#include <fstream>


#include "foxes.h"
#include "util.h"
#include "grid.h"
using namespace std;

//reads coordinates from file and assigns them to the two arrays
void LoadFoxes(int foxesX[], int foxesY[], int numFoxes)
{
    //FILL THIS FUNCTION
    ifstream myfile;
    myfile.open("foxes.txt", ios::in); //Allows input from stream
    if(myfile)
    {
        int numFoxes;
        for(int numFoxes = 0; numFoxes<5; numFoxes++) //Number of elements in foxes file for x & y array
        {

            myfile>>foxesX[numFoxes];
            myfile>>foxesY[numFoxes];

        }
        myfile.close();


    }
    else
        cout << "Could not open file" << endl;
}
//random fox movement, not considering rabbit's location
void RandMoveFoxes(int foxesX[], int foxesY[], bool stationary, int numFoxes)
{

    for(int i=0; i<numFoxes; i++)
    {
        AutonomousMove(foxesX[i], foxesY[i]);
        EdgeDetect(foxesX[i], foxesY[i]);
    }
}
//SetFoxes controls movements of foxes. It will generate randCoord movements if prompted, and if not, will remain in predetermined positions
void SetFoxes(int foxesX[], int foxesY[], bool RandPositions, int numFoxes)
{
    if(RandPositions == true)
    {
        for(int i=0; i<numFoxes; i++)
        {
            foxesX[i] = randCoord(23,1);
            foxesY[i] = randCoord(23,1);
        }
    }
    else
        LoadFoxes(foxesX, foxesY, numFoxes);
}
