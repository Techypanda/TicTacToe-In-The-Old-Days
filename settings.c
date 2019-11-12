#include "settings.h"
#include "board.h"
/* #include "error.h" COMBINED INTO COMMONLIB */
#include <stdio.h>
#include <stdlib.h>
#include "commonlib.h"
/*
    Author: Jonathan Wright 19779085
    Purpose: This is a C file relating to settings files.
    Date: 7/10/2019, 11:45pm
*/

/*
    IMPORTS: char* filename (file to open)
    EXPORTS: struct board - tictactoe board.
    PURPOSE: read settings from file, validate it using validators and return NULL if invalid.
    DATE: 7/10/2019, 11:45pm
*/
board* readSettings(char* filename)
{
    FILE* file;
    int width;
    int height;
    int tiles;
    int nRead;
    board* board;
    board = NULL;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error Occurred Opening file '%s'\n", filename);
    }
    else
    {
        /* Read From File */
        nRead = fscanf(file, "M=%d\n", &width);
        if (invalidRead(nRead) == FALSE)
        {
            nRead = fscanf(file, "N=%d\n", &height);
            if (invalidRead(nRead) == FALSE)
            {
                nRead = fscanf(file, "K=%d\n", &tiles);
                if (invalidRead(nRead) == FALSE)
                {
                    board = createBoard(width,height,tiles); /* BOARD SUCCESSFULLY CREATED */
                }
                else
                { /* ERROR WITH TILE ROW VALUE */
                    errorPrint("Error Occured Reading Tile Row Count Value.");
                }
            }
            else
            { /* ERROR WITH HEIGHT VALUE */
                errorPrint("Error Occured Reading Height Value.");
            }
        }
        else
        { /* ERROR WITH WIDTH VALUE */
            errorPrint("Error Occured Reading Width Value.");
        }
        /* READ COMPLETE CLEANUP TIME */
        if (ferror(file))
        {
            perror("Error occured during read, discarding board!");
            free(board); /* FREE OLD BOARD. */
            board = NULL; /* Discard Board. */
        }
        fclose(file);
    }
    return board; /* Will Return Null if Its invalid. */
}

/*
    IMPORTS: int nRead (num items read or EOF constant)
    EXPORTS: validity (is read okay?)
    PURPOSE: check input is valid.
    DATE: 7/10/2019, 11:47pm
*/
int invalidRead(int nRead)
{
    int validity = FALSE;
    if (nRead > 1 || nRead < 1 || nRead == EOF)
    {
        validity = TRUE;
    }
    return validity;
}

/*
    IMPORTS: board gameBoard (Board to read settings of.)
    EXPORTS: None
    PURPOSE: To display the settings of the gameboard to user.
    DATE: 8/10/2019 3:52am
*/
void displaySettings(board gameBoard)
{
    printf("Width: %d\nHeight: %d\nX needed in row to win: %d\n", gameBoard.width,
    gameBoard.height, gameBoard.tiles);
}

/*
    IMPORTS: board* gameBoard (Changing M N K values of board.)
    EXPORTS: None
    Purpose: Editor Complimation that lets you edit board.
    DATE: 13/10/2019 2:18am
*/
void editor(board* gameBoard)
{
    int m;
    int n;
    int k;
    char bufferWaster[5];
    int validity = FALSE;
    while (validity == FALSE)
    {
        printf("Enter New M,N,K Values in the format M,N,K\n");
        scanf("%d,%d,%d",&m,&n,&k);
        validity = boardValidity(m,n,k);
        if (validity == TRUE)
        {
            printf("Updated Values\n");
        }
        else
        {
            /*errorPrint("Invalid choice! The options are 1 to 5."); Error printed by boardValidity */
            fgets(bufferWaster,5,stdin); /* Waste Buffer */
        }
    }
    gameBoard->width = m;
    gameBoard->height = n;
    gameBoard->tiles = k;
}
