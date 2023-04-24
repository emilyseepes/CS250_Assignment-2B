//RESOURCES USED:
//Lecture 9/8/2022 Notes: Modules
//Lecture 3: The Structure of C Program- Part 1 (video) (***Second Video***)
// ~was unsure if I was able to use header files in different .cpp files but this answered that question
//Lab 5- Multi-file Projects- Part 2

//***In each header file, I included why I put each function in that designated location!***

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <windows.h>
#include <fstream>
#include <math.h>
#include <iomanip>

#include "foxes.h"
#include "grid.h"
#include "rabbits.h"
#include "util.h"
using namespace std;

int main()
{
    int turns = 0;
    int score = 0;
    int numRabbits = 15;
    int numFoxes = 5;

    //Pulling this information to implement cases in Menu function
    bool stationary = true;
    bool RandPositions = true;
    bool randMove      = true;


    srand(time(NULL));

    char grid[25][25];
    int rabbitsX[numRabbits];
    int rabbitsY[numRabbits];
    int foxesX[numFoxes];
    int foxesY[numFoxes];

    //Menu set to true for all arguments
    Menu(RandPositions, stationary, randMove);


    SetRabbits(rabbitsX, rabbitsY, RandPositions, numRabbits);
    SetFoxes(foxesX, foxesY, RandPositions, numFoxes);
    GridInit(grid);
    SetGrid(grid);
    UpdateGrid(rabbitsX, rabbitsY, foxesX, foxesY, grid, score, numRabbits, numFoxes);
    PrintMap(grid, score, turns);

    while(turns<100 && score != numRabbits)
    {
        ResetRabbits(grid, rabbitsX, rabbitsY, numRabbits);
        ResetFoxes(grid, foxesX, foxesY, numFoxes);
        if(stationary == false)
            MoveRabbits(rabbitsX, rabbitsY, stationary, numRabbits);
        if(randMove == true)
            RandMoveFoxes(foxesX, foxesY, stationary, numFoxes);
        else
            MoveFoxesAI(foxesX, foxesY, rabbitsX, rabbitsY, numRabbits, numFoxes);
        UpdateGrid(rabbitsX, rabbitsY, foxesX, foxesY, grid, score, numRabbits, numFoxes);
        Sleep(500);
        PrintMap(grid, score, turns);
        turns++;
    }

    SaveScore(score, randMove, stationary);

    return 0;
}

//MATERIALS USED:
// Malik, D. S. (2018).
//In C++ programming: From problem analysis to program design. Hard Copy Book, Cengage Learning.
//(pp. 160–173) FOR FILES
//(pp. 619-622) FOR ARRAYS IN STRUCT
// Lecture 9/8/2022 and Lecture 9/13/2022 notes


