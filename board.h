/*
    AUTHOR: Jonathan Wright
    DATE: 7/10/2019, 9:56pm
    PURPOSE: board functionality and functions included in this headerfile.
*/
#include "list.h"
#ifndef BOARD
#define BOARD
/*
    Purpose: This struct will store details about the tictactoe board.
    Date: 8/10/2019
    Author: Jonathan Wright
*/
typedef struct board {
    int width;
    int height;
    int tiles;
    int secret;
    int editor;
    linkedList* games;
} board;

board* createBoard(int m, int n, int k);
int boardValidity(int inWidth, int inHeight, int tileCount);
#endif
