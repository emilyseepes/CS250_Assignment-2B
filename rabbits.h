#ifndef RABBITS_H_INCLUDED
#define RABBITS_H_INCLUDED
//THIS FILE MAINLY DEALS WITH THE RABBITS MOVEMENTS

//loads rabbit coordinates from file
//LoadRabbits takes predetermined coordinates from file and will move them to such positions
void LoadRabbits(int rabbitsX[],int rabbitsY[], int numRabbits);

//MoveRabbits will move rabbits around the grid (not in predetermined coordinates)
void MoveRabbits(int rabbitsX[],int rabbitsY[], bool stationary, int numRabbits);
#endif // RABBITS_H_INCLUDED

//generates random coordinates for rabbits or load from file
void SetRabbits(int rabbitsX[],int rabbitsY[], bool RandPositions, int numRabbits);
