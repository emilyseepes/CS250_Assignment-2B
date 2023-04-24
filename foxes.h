#ifndef FOXES_H_INCLUDED
#define FOXES_H_INCLUDED

//**THIS FILE MAINLY DEALS WITH THE RABBITS MOVEMENTS**


//reads coordinates from file and assigns them to the two arrays
//LoadFoxes takes predetermined coordinates that will place foxes in certain position
void LoadFoxes(int foxesX[], int foxesY[], int numFoxes);

//RandMoveFoxes generates random movements for foxes: not predetermined coordinates
void RandMoveFoxes(int foxesX[], int foxesY[], bool stationary, int numFoxes);

//SetFoxes controls movements of foxes. It will generate randCoord movements if prompted, and if not, will remain in predetermined positions
void SetFoxes(int foxesX[], int foxesY[], bool RandPositions, int numFoxes);

#endif // FOXES_H_INCLUDED
