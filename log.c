#include "board.h"
#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    Purpose: This file is to do with structs relating to logFile display/writing.
    Author: Jonathan Wright
    Date: 13/10/2019 1:47am
*/

/*
    Purpose: display the logfile to stream (stdout or file)
    Date: 13/10/2019 1:34am
    Imports: board* gameBoard, FILE* stream
    Exports: none
*/
void displayLog(board* gameBoard, FILE* stream)
{
    turn* currTurn;
    int count;
    int turn;
    listNode* currGameNode;
    game* currGame;
    listNode* currTurnNode;
    count = 0;
    currGameNode = gameBoard->games->head;
    fprintf(stream, "SETTINGS: \n    M: %d\n    N: %d\n    K: %d\n\n",
    gameBoard->width, gameBoard->height, gameBoard->tiles);
    while (currGameNode != NULL)
    {
        turn = 0;
        count++;
        fprintf(stream, "GAME: %d\n", count);
        currGame = (game*)currGameNode->data;
        currTurnNode = currGame->turns->head;
        while (currTurnNode != NULL)
        {
            turn++;
            currTurn = /*(turn*)*/currTurnNode->data; /* Cant Typecast...??? */
            fprintf(stream, "    Turn: %d\n    Player: %c\n    Location: %d,%d\n\n", turn, currTurn->player, currTurn->location[0], currTurn->location[1]);
            currTurnNode = currTurnNode->next;
        }
        currGameNode = currGameNode->next;
    }
}
/*
    Purpose: error checking and opening of the desired file, then passed
    to displayLog
    Date: 13/10/2019 1:34am
    Imports: board* gameBoard
    Exports: none
*/
void saveLog(board* gameBoard)
{
    FILE* file;
    time_t currTime;
    struct tm* timeStruct;
    char fileString[999]; /* 999 Max FileName Length. */
    time(&currTime);
    timeStruct = localtime(&currTime);
    sprintf(fileString, "MNK_%d-%d-%d_%d-%d_%d-%d.log",
        gameBoard->width, gameBoard->height, gameBoard->tiles, /* MNK */
        timeStruct->tm_hour, timeStruct->tm_min, /* HOUR-MIN */
        timeStruct->tm_mday, timeStruct->tm_mon + 1 /* DAY-MONTH */
    );
    file = fopen(fileString, "w"); /* Overwrite/Write */
    if (file != NULL)
    {
        displayLog(gameBoard, file);
        if (ferror(file))
        {
            perror("An error occurred writing to log file!\n");
        }
        printf("Saved To File! '%s'\n", fileString);
        fclose(file);
    }
    else
    {
        perror("An error has occurred attempting to open a log file.\n");
    }
}
/*
    Purpose: creates a turn struct which is a turn in the game.
    Date: 13/10/2019 1:34am
    Imports: char inPlayer, int inX, int inY
    Exports: turn* outTurn
*/
turn* createTurn(char inPlayer, int inX, int inY)
{
    turn* outTurn;
    outTurn = (turn*)malloc(sizeof(turn));
    outTurn->player = inPlayer;
    outTurn->location[0] = inX;
    outTurn->location[1] = inY;
    return outTurn;
}
/*
    Purpose: creates a new game struct which is a new game of tictactoe.
    Date: 13/10/2019 1:34am
    Imports: none
    Exports: game* newGame
*/
game* newGame()
{
    game* newGame;
    newGame = (game*)malloc(sizeof(game));
    newGame->turns = createLinkedList();
    return newGame;
}
/*
    Purpose: free the turns list within the current game.
    Date: 17/10/2019 1:34am
    Imports: void* data
    Exports: none
*/
void freeTurn(void* data)
{
    turn* currTurn = (turn*)data;
    free(currTurn);
}
/*
    Purpose: free the game list within the current game.
    Date: 17/10/2019 1:34am
    Imports: void* data
    Exports: none
*/
void freeGame(void* data)
{
    game* currGame = (game*)data;
    freeLinkedList(currGame->turns, *freeTurn);
    free(currGame);
}
