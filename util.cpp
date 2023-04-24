#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <ostream>      // std::flush
#include <windows.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "util.h"

using namespace std;

//generates random numbers 0 or 1
int coinToss()
{
    return rand() % 2;
}

int randCoord(int ceiling, int floor)
{
    return floor + rand() % (( ceiling + 1 ) - floor);
}

//returns the direction towards the closest rabbit, given a foxes coordinates x and y
char ClosestRabbit(int x, int y, int rabbitsX[],int rabbitsY[], int numRabbits)
{

    double minDistance = 25;
    double temp_dist = -1;
    double v_distance = -1;
    double  h_distance = -1;

    //iterates through all rabbits and calculates their distance from fox's coordinates
    for(int i=0; i<numRabbits; i++)
    {
        if(rabbitsX[i]!= -1 && rabbitsY[i] != -1) // we dont consider rabbits that have been captured
        {
            temp_dist = (double)sqrt(pow(x - rabbitsX[i],2)+pow(y - rabbitsY[i],2));
            if(temp_dist<minDistance) //we keep track of minimum Distance
            {
                minDistance = temp_dist;
                v_distance = x - rabbitsX[i];
                h_distance = y - rabbitsY[i];
            }
        }
    }

    //if rabbit is closer in the vertical direction
    if(fabs(v_distance) > fabs(h_distance))
    {
        if(v_distance>0) //if distance is positive, move up
            return 'w';
        else
            return 's'; //otherwise move down
    }
    else
    {
        if(h_distance>0)
            return 'a';
        else
            return 'd';
    }
}

//foxes and rabbits move randomly, if they try to move beyond the grid, stop them
//by adjusting their coordinates, if variable is 0 or greater than 23, it should be adjusted to 1 and 24 respectively
void EdgeDetect(int &x, int &y)
{
    //FILL THIS FUNCTION
    if(x <= 0) //If variable x or is 0 or less, automatically adjust to 1
        x = 1;
    if(y <= 0)
        y = 1;
    if(x > 23) //If variable x or y is greater than 23, adjust it to value of 24
        x = 24;
    if (y > 23)
        y = 24;

}

/*
randomly chooses where to move a rabbit or fox
uses random number generator to determine where to go
updates the x and y coordinates. You do not need to implement
your own random number generator. Instead, use the coinTossn function
*/
void AutonomousMove(int &x, int &y)
{
    //FILL THIS FUNCTION
    int axis = coinToss();
    int direction = coinToss();
    //Create nested if/else loops in order to allow 'o' and 'X' to move up, down, left, right
    if (axis == 0)
    {
        if (direction == 0)
        {
            x++; // x will shift left
        }
        else
        {
            x--; //x will shift right
        }
    }
    else
    {
        if (direction == 0)
        {
            y++; // y shifts up
        }
        else
        {
            y--; // y moves down
        }
    }

//Set reference x & y to random number generator to produce random move
}

/*
This function implements the Menu functionality
It keeps track of the game modes RandPositions, stationary, and Random Fox movement which are then passed to other methods to alter functionality. Besides printing the menu, it sets the game modes(boolean variables passed as parameters) so make sure that they are set before exiting the function.
*/

void Menu(bool &RandPositions, bool &stationary, bool &randMove)
{

    //FILL THIS FUNCTION

    int action; // int for user to input some type of option within Menu

    do //do while loop to allow menu to stay on screen while adjusting modes. Will only exit if action == 0 || action == 1 (Launch and executes)
    {
        cout << "Launch" << setw(29)<< "(1)" << endl;
        cout << "Import Positions from File" << setw(9) << "(2)" << endl;
        cout << "Random Positions" << setw(19) << "(3)" << endl;
        cout << "Stationary Rabbits" << setw(17) << "(4)" << endl;
        cout << "Moving Rabbits" << setw(21) << "(5)" << endl;
        cout << "Random Fox Movement" << setw(16) << "(6)" << endl;
        cout << "Chase Fox Movement" << setw(17) << "(7)" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Stationary Rabbits: "<< setw(14) << stationary << endl;
        cout << "Random Fox Movement: " << setw(13) << randMove << endl;
        cout << "Random Positions: " << setw(16) << RandPositions << endl;
        cout << endl <<"Enter Action:";
        cin >> action;


        switch(action)
        {
        case 0:
            exit(0); //Will break out of entire program
            break;
        //Launch
        case 1:
            break; //Terminates loop to launch game

        case 2:
            //if (2), load coordinates from rabbit and foxes files
            //Will also set 'Random Position' to 0 as file has specific coordinates
            RandPositions = false;

            break;


        case 3:
            // if (3), coordinates will be randomly generated;
            RandPositions = true;




        case 4:
            // if (4), rabbits will stay in the same coordinates

            stationary = true;
            break;


        case 5:

            stationary = false;
            // if (5), rabbits will roam grid randomly
            break;

        case 6:
            randMove = true;
            // if (6), foxes will roam grid randomly
            break;
        case 7:
            randMove = false;

            // if (7), foxes will move to closest rabbits
            break;
        default:
            break;

        }//switch bracket

    }
    while (action != 1);  //while action does not equal 1 (which will launch program to run)

}//menu


//checks if capture occurs
//If rabbit is on an square next to the fox, or they are in the same square, capture happens
bool Capture(int x, int y, char grid[25][25])
{
    if(grid[x][y] == 'X' || grid[x+1][y] == 'X' || grid[x-1][y] == 'X' || grid[x][y+1] == 'X' || grid[x][y-1] == 'X')
        return true;
    else
        return false;
}

void MoveFoxesAI(int foxesX[], int foxesY[], int rabbitsX[],int rabbitsY[], int numRabbits, int numFoxes)
{
    char direction = ' ';
    for(int i=0; i<numFoxes; i++)
    {
        //determine direction to closest rabbit, for fox "i"
        direction = ClosestRabbit(foxesX[i], foxesY[i], rabbitsX, rabbitsY, numRabbits);
        //update coordinates based on direction
        if(direction == 'a')
            foxesY[i]-=1;
        else if(direction == 'w')
            foxesX[i]-=1;
        else if(direction == 'd')
            foxesY[i]+=1;
        else if(direction == 's')
            foxesX[i]+=1;
        EdgeDetect(foxesX[i], foxesY[i]);
    }
}



//This function is activated when a best score has been beaten
// it prompts the user for an alias
//and prints the alias along with score on the 'leaderboard.txt' file
void SaveScore(int score, bool RandMove, bool stationary)
{
    string alias;
    ofstream outfile;
    outfile.open("leaderboard.txt");
    if(stationary == true)
        outfile<<" Stationary Rabbits,";
    else
        outfile<<" Moving     Rabbits,";
    if(RandMove == true)
        outfile<<" Random Fox Movement,";
    else
        outfile<<"Chase  Fox Movement,";
    outfile<<" Turns:"<<score<<endl;
    outfile.close();

}


