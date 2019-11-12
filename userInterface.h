#include "board.h"
#ifndef USERINTERFACE
#define USERINTERFACE
void menu(board* gameBoard);
void callSelection(int selection, board* gameBoard);
int validChoice(int selection, int secret, int editor);
#endif
