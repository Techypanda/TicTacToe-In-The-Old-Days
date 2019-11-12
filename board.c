/*
    Author: Jonathan Wright 19779085
    Purpose: This is a C file purely for methods related to the creation/use of a board struct.
    Date: 7/10/2019, 9:50pm
*/

#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "commonlib.h"

/*
    IMPORTS: integer m (width), integer n (height), integer k (matching tiles)
    EXPORTS: struct board - outBoard
    PURPOSE: A board structure named outBoard will be created based on imports.
    DATE: 7/10/2019, 9:52pm
    ASSERTION: There will be no invalid board output.
*/
board* createBoard(int m, int n, int k)
{
    board* outBoard;
    outBoard = (board*)malloc(sizeof(board));
    if (boardValidity(m,n,k) == TRUE) /* Valid Inputs For A Board. */
    {
        outBoard->width = m;
        outBoard->height = n;
        outBoard->tiles = k;
        outBoard->games = createLinkedList();
    }
    else
    {
        /* Errors were output by the validitors to user about the invalid inputs. */
        outBoard = NULL; /* Return a NULL pointer as imports were invalid. */
    }
    return outBoard;
}

/*
    DATE: 7/10/2019
    IMPORTS: int inWidth (width of board), int inHeight (height of board), int tileCount (tiles in row)
    EXPORTS: int validity (whether its valid or not)
    PURPOSE: to validate the width/Height/tileCount and output associated error messages.
*/
int boardValidity(int inWidth, int inHeight, int tileCount)
{
    int validity = TRUE; /* Assume its true. */
    if (inWidth < 1)
    {
        errorPrint("Cannot create a board of width < 1.");
        validity = FALSE;
    }
    else if (inHeight < 1)
    {
        errorPrint("Cannot create a board of height < 1.");
        validity = FALSE;
    }
    else if (tileCount < 1)
    {
        errorPrint("Cannot have <1 tiles in a row as the win condition.");
        validity = FALSE;
    }
    else if (inHeight > 999)
    {   /* This is a assumption i made, if your use of this tictactoe can display */
        /* >999 then you should change this minor error */
        minorError("A height greater than 999 will display very strange on a terminal.");
    }
    else if (inWidth > 999)
    { /* This is a assumption i made, if your use of this tictactoe can display
        >999 then you should change this minor error */
        minorError("A width greater than 999 will display very strange on a terminal.");
    }
    else if (tileCount > 999)
    {
        minorError("having >999 tiles in a row as the win condition will be a very boring game.");
    }
    else if (tileCount > inWidth && tileCount > inHeight)
    {
        errorPrint("Cannot have that many tiles in a row as the win condition.");
        validity = FALSE;
    }
    return validity;
}
/*
    DATE: 7/10/2019
    IMPORTS: board* board (board to free)
    EXPORTS: none
    PURPOSE: To free a board.
*/
void freeBoard(board* board)
{
    free(board);
}
