#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

//DEALS WITH CODE RELATED TO PRINTING, UPDATING, AND QUERYING CHARACTERISTICS RELATED TO GRID

//SetGrid creates the borders for the grid
void SetGrid(char grid[25][25]);

//Through each movement, grid will update the graphics of "o" and "X" while also making sure both remain inside grid and a rabbit was not captured
void UpdateGrid(int rabbitsX[],int rabbitsY[], int foxesX[], int foxesY[], char grid[25][25], int &score, int numRabbits, int numFoxes);

//Prints the borders of the Map, and also keeps count of the total rabbits captured (score) and the total iterations of the game play
void PrintMap(char grid[25][25], int score, int turns);


//initializes the grid 2D array
void GridInit(char grid[25][25]);
//since foxes move, we clear their last position


//Will validate that each position (up, down, left, right) remains within the Map and does not go out of bounds
bool InvalidPos(int x, int y);

//Queries the positions of foxes and rabbits on the grid (x & y)
bool Capture(int x, int y, char grid[25][25]);

//ResetFoxes will clear the last position of "X", so that the "X" will not graphically occupy the same spot. Updates the grid by clearing foxes last marked position on map
void ResetFoxes(char grid[25][25], int foxesX[], int foxesY[], int numFoxes);

//ResetRabbits will clear the last position of "o", so that the "o" will not graphically occupy the same spot. Updates the grid by clearing rabbits last marked position on map
void ResetRabbits(char grid[25][25], int rabbitsX[], int rabbitsY[], int numRabbits);
#endif // GRID_H_INCLUDED

