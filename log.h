#include "board.h"
#include <stdio.h>
#ifndef LOG
#define LOG
void displayLog(board* gameBoard, FILE* stream);
/*
    Purpose: This struct contains game turns
    Date: 12/10/2019
    Author: Jonathan Wright
*/
typedef struct game
{
    linkedList* turns;
} game;
/*
    Purpose: This struct contains turn related information
    Date: 12/10/2019
    Author: Jonathan Wright
*/
typedef struct turn
{
    char player;
    int location[2];
} turn;
turn* createTurn(char inPlayer, int inX, int inY);
void freeTurn(void* data);
void freeGame(void* data);
void saveLog(board* gameBoard);
game* newGame();
#endif
