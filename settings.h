#include "board.h"
#ifndef SETTINGS
#define SETTINGS
board* readSettings(char* filename);
int invalidRead(int nRead);
void displaySettings(board gameBoard);
void editor(board* gameBoard);
#endif
