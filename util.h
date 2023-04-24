#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


// THIS FILE INCLUDES FUNCTIONS UTILIZED BY BOTH THE RABBITS AND FOXES MODULES

//generates random numbers 0 or 1
//coinToss is called in AutonomousMove, which is utilized by BOTH in MoveRabbit and RandMoveFoxes
int coinToss();

//generates random coordinates for the grid
//randCoord is used in BOTH SetFoxes and SetRabbits
int randCoord(int ceiling, int floor);

//ClosestRabbit requires BOTH rabbit's coordinates and then moves according to foxes x and y
//returns the direction towards the closest rabbit, given a foxes coordinates x and y
char ClosestRabbit(int x, int y, int rabbitsX[],int rabbitsY[], int numRabbits);

//Used by BOTH RandMoveFoxes and MoveRabbits to stay in bounds
//foxes and rabbits move randomly, if they try to move beyond the grid, stop them
//by adjusting their coordinates, if variable is 0 or greater than 23, it should be adjusted to 1 and 24 respectively
void EdgeDetect(int &x, int &y);

//Used by BOTH RandMoveFoxes and MoveRabbits
void AutonomousMove(int &x, int &y);


void Menu(bool &RandPositions, bool &stationary, bool &randMove);

//Uses XY coordinates of Rabbit to move Fox XY accordingly. Utilizes BOTH positions
void MoveFoxesAI(int foxesX[], int foxesY[], int rabbitsX[],int rabbitsY[], int numRabbits, int numFoxes);



//This function is activated when a best score has been beaten
// it prompts the user for an alias
//and prints the alias along with score on the 'leaderboard.txt' file
void SaveScore(int score, bool RandMove, bool stationary);

#endif // UTIL_H_INCLUDED
