#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "commonlib.h"
#include "board.h"
#include "settings.h"
#include "userInterface.h"
/*
    Author: Jonathan Wright
    Date: 8/10/2019 2:59am
    Purpose: This is the where the main method will be located and will run all
    other parts of the program.
*/
int main(int argc, char** argv)
{
    board* gameBoard;
    if (argc == 2)
    {
        gameBoard = readSettings(*(argv + 1));
        if (gameBoard != NULL)
        { /* Meaningful Error Already Printed to user if it was NULL (Program Will End)*/
            /* ^ Will Add Settings: To log file. */
            gameBoard->secret = FALSE;
            gameBoard->editor = FALSE;
            #ifdef SECRET /* CONDITIONAL COMPI */
                gameBoard->secret = TRUE;
            #endif
            #ifdef EDITOR
            /* Editor Conditional Compli */
                gameBoard->editor = TRUE;
            #endif
            menu(gameBoard);
        }
    }
    else
    {
        errorPrint("Incorrect usage of program, should have one commandline parameter");
        printf("Correct usage example: ./TicTacToe filename.txt\n");
    }
    return(1);
}
