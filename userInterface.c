/*
    Purpose: This file will be how the user will interact with the program.
    Author: Jonathan Wright
    Date: 8/10/2019
*/

#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInterface.h"
#include "commonlib.h"
#include "game.h"
#include "board.h"
#include "settings.h"

/*
Purpose: To loop until the user selects a option
Date: 8/10/2019
Imports: None
Exports: None
*/
void menu(board* gameBoard)
{
    char bufferWaster[5];
    int selection = -1;
    int validity;
    do
    {
        printf("---------------------------------------------------\n");
        printf("1: Start a new game\n");
        printf("2: View the settings of the game\n");
        printf("3: View the current logs\n");
        if (gameBoard->secret != TRUE)
        {
            printf("4: Save the logs to file\n");
        }
        printf("5: Exit the application\n");
        if (gameBoard->editor == TRUE)
        {
            printf("6: Change MNK Values\n");
        }
        printf("---------------------------------------------------\n");
        scanf("%d",&selection);
        fgets(bufferWaster, 5, stdin);
        if (strlen(bufferWaster) > 1) /* This is a quick fix for a problem i found
        with doubles. */
        {
            selection = -1;
            validity = FALSE;
            printf("That is a invalid input.\n");
        }
        else
        {
            validity = validChoice(selection, gameBoard->secret, gameBoard->editor);
        }
        if (validity == TRUE)
        {
            callSelection(selection, gameBoard);
        }
    } while (selection != 5);
}
/*
    Purpose: Validate Input is a option.
    Date: 8/10/2019
    Imports: char selection (input to verify.), int secret (conditional compiliation)
             int editor (conditional complimation)
    Exports: none
*/
int validChoice(int selection, int secret, int editor)
{
    char bufferWaster[5]; /* String to waste buffer into */
    int validity = FALSE; /* Start By Assuming Invalid */
    if (editor == TRUE && secret == TRUE)
    {
        if (selection > -1 && selection < 7 && selection != 4)
        {
            validity = TRUE;
        }
        else
        {
            errorPrint("Invalid choice! The options are 1 to 5.");
            fgets(bufferWaster,5,stdin); /* Waste Buffer */
        }
    }
    else if (editor == TRUE)
    {
        if (selection > -1 && selection < 7)
        {
            validity = TRUE;
        }
        else
        {
            errorPrint("Invalid choice! The options are 1 to 5.");
            fgets(bufferWaster,5,stdin); /* Waste Buffer */
        }
    }
    else if (secret == TRUE)
    {
        if (selection > -1 && selection < 6 && selection != 4)
        {
            validity = TRUE;
        }
        else
        {
            errorPrint("Invalid choice! The options are 1 to 5.");
            fgets(bufferWaster,5,stdin); /* Waste Buffer */
        }
    }
    else if (selection > -1 && selection < 6)
    {
        validity = TRUE;
    }
    else
    {
        errorPrint("Invalid choice! The options are 1 to 5.");
        fgets(bufferWaster,5,stdin); /* Waste Buffer */
    }
    return validity;
}
/*
    Purpose: Call the associated function to selection
    Date: 8/10/2019
    Imports: char selection
    Exports: none
*/
void callSelection(int selection, board* gameBoard)
{
    switch (selection)
    {
        case 1: /* Start Game */
            startGame(gameBoard);
            break;
        case 2: /* View Settings */
            displaySettings(*gameBoard);
            break;
        case 3: /* View Logs */
            displayLog(gameBoard, stdout);
            break;
        case 4: /* Save Logs */
            saveLog(gameBoard);
            break;
        case 5: /* Exit */
            freeLinkedList(gameBoard->games, *freeGame);
            free(gameBoard);
            break;
        case 6: /* EDITOR */
            editor(gameBoard);
            break;
    }
}
