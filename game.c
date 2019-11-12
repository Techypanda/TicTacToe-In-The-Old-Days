/*
    Purpose: Tictactoe game logic is stored in this file.
    Author: Jonathan Wright
    Date: 8/10/2019
*/
#include "commonlib.h"
#include "board.h"
#include "game.h"
#include "log.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
    Purpose: Start The Game.
    Date: 13/10/2019 1:34am
    Imports: board* gameBoard
    Exports: none
*/
void startGame(board* gameBoard)
{
    int currTurn;
    int rows;
    int columns;
    int i;
    int first;
    char** ticTacToeBoard;
    insertLast(gameBoard->games, newGame()); /* Insert Game With Turns List */
    currTurn = 0; /* This is the current turn, if > max turns then tie. */
    rows = gameBoard->height;
    columns = gameBoard->width;

    ticTacToeBoard = (char**)malloc(rows * sizeof(char*));
    for (i = 0; i < rows; i++)
    {
        ticTacToeBoard[i] = (char*)malloc((columns + 1) * sizeof(char)); /* Null Terminator */
        initRow(ticTacToeBoard[i],columns);
    }
    displayBoard(ticTacToeBoard, rows, columns);
    first = (rand() % 2);
    /*printf("Player %d Begins First.\n", first + 1);*/
    nextTurn(first, ticTacToeBoard, rows, columns, gameBoard->tiles, currTurn + 1, ((game*)gameBoard->games->tail->data)->turns);
    /* tail is the current game linkedList. */
}

int checkForFloat(char* line)
{
    int i;
    int isFloat = FALSE;
    for (i = 0; i < strlen(line); i++)
    {
        if (line[i] == '.')
        {
            isFloat = TRUE;
        }
    }
    return isFloat;
}
/*
    Purpose: Recursive method for each turn.
    Date: 13/10/2019 1:34am
    Imports: int player, char** ticTacToeBoard, int rows, int columns, int win, int currTurn, linkedList* currGame
    Exports: none
*/
void nextTurn(int player, char** ticTacToeBoard, int rows, int columns, int win, int currTurn, linkedList* currGame)
{
    char invalidInput[22]; /* To Flush Input Stream */
    char line[22]; /* 2147483647(10 characters) so at max just need to read (10 * 2 chars) 2147483647,2147483647 */
    int victory;
    int acceptedInput = FALSE;
    int placement[2]; /* x , y */
    placement[0] = -1; /* Initial Values */
    placement[1] = -1; /* initial Values */
    printf("Player %d's turn.\n",player+1);
    printf("Please enter a tile in the format x,y noting (0,0) is top left.\n");
    while (acceptedInput == FALSE)
    {
        scanf("%s",line);
        if (checkForFloat(line) == FALSE)
        {
            sscanf(line, "%d,%d", placement + 0, placement + 1);
            acceptedInput = inAcceptableRange(placement, rows, columns);
            if (acceptedInput == TRUE)
            { /* WITHIN RANGE */
                acceptedInput = notTaken(ticTacToeBoard, placement);
            }
        }
        else
        {
            printf("That is a float!\nPlease enter a tile in the format x,y noting (0,0) is top left.\n");
        }
        fgets(invalidInput,22, stdin);
    }
    if (player == 0)
    {
        insertLast(currGame, createTurn('X', placement[0], placement[1]));
        printf("Player: %c, Location: %d,%d\n", ((turn*)currGame->tail->data)->player, ((turn*)currGame->tail->data)->location[0], ((turn*)currGame->tail->data)->location[1]);
        ticTacToeBoard[placement[1]][placement[0]] = 'X';
    }
    else
    {
        insertLast(currGame, createTurn('O', placement[0], placement[1]));
        printf("Player: %c, Location: %d,%d\n", ((turn*)currGame->tail->data)->player, ((turn*)currGame->tail->data)->location[0], ((turn*)currGame->tail->data)->location[1]);
        ticTacToeBoard[placement[1]][placement[0]] = 'O';
    }
    displayBoard(ticTacToeBoard, rows, columns);
    victory = checkForVictory(ticTacToeBoard, placement[1],placement[0],win, rows, columns, player);
    if (victory == TRUE)
    {
        printf("Player %d has won the game, returning to menu.\n", player+1);
        cleanUp(ticTacToeBoard,rows,columns);
    }
    else if (currTurn == rows * columns)
    {
        printf("The game has ended in a draw.\n");
        cleanUp(ticTacToeBoard,rows,columns);
    }
    else
    {
        if (player == 0)
        {
            nextTurn(1,ticTacToeBoard,rows,columns,win,currTurn + 1,currGame);
        }
        else
        {
            nextTurn(0,ticTacToeBoard,rows,columns,win,currTurn + 1,currGame);
        }
    }
}

/*
    Purpose: Cleanup for the game. (Freeing)
    Date: 13/10/2019 1:34am
    Imports: char** ticTactoeBoard, int rows, int columns
    Exports: none
*/
void cleanUp(char** ticTacToeBoard, int rows, int columns)
{
    int i;
    for (i = 0; i < rows; i++)
    {
        free(ticTacToeBoard[i]);
        ticTacToeBoard[i] = NULL;
    }
    free(ticTacToeBoard);
    ticTacToeBoard = NULL;
}
/*
    Purpose: method that will check the position is not taken on the board.
    Date: 13/10/2019 1:34am
    Imports: char** ticTacToeBoard, int placement[2]
    Exports: int notTaken
*/
int notTaken(char** ticTacToeBoard, int placement[2])
{
    int notTaken = FALSE;
    if (ticTacToeBoard[placement[1]][placement[0]] == (char)0)
    {
        notTaken = TRUE; /* Empty Spot */
    }
    else
    {
        printf("x: %d, y: %d is not empty!\n", placement[0],placement[1]);
        printf("Please enter a tile in the format x,y noting (0,0) is top left.\n");
    }
    return notTaken;
}
/* This Will Initilize The Arrays Similar To Calloc */
/*
    Purpose: method that initilizes row with empty characters.
    Date: 13/10/2019 1:34am
    Imports: char* row, int columns
    Exports: none
*/
void initRow(char* row, int columns)
{
    int i;
    for (i = 0; i < columns; i++)
    {
        row[i] = (char)0; /* Empty Character */
    }
}
/*
    Purpose: display the current board.
    Date: 13/10/2019 1:34am
    Imports: char** ticTacToeBoard, int rows, int columns
    Exports: none
*/
void displayBoard(char** ticTacToeBoard, int rows, int columns)
{
    int i;
    /* This formula gives you the length of line for my given format */
    int lineLength = (3 * columns) + (columns + 1);
    printBorder('=',lineLength);
    for (i = 0; i < rows; i++)
    {
        printRow(ticTacToeBoard[i], columns);
        if (i + 1 != rows)
        {
            printBorder('-',lineLength);
        }
    }
    printBorder('=',lineLength);
}
/*
    Purpose: print a border in the chat
    Date: 13/10/2019 1:34am
    Imports: char chosenChar, int lineLength
    Exports: none
*/
void printBorder(char chosenChar, int lineLength)
{
    int i;
    for (i = 0; i < lineLength; i++)
    {
        printf("%c",chosenChar);
    }
    printf("\n");
}
/*
    Purpose: print a row from the array.
    Date: 13/10/2019 1:34am
    Imports: char* tictacToeBoard, int columns
    Exports: none
*/
void printRow(char* ticTacToeBoard, int columns)
{
    int i;
    if (ticTacToeBoard[0] == 0) /* 0 . The null/empty char is simply a value of zero */
    {
        printf("|   "); /* First Character */
    }
    else
    {
        printf("| %c ", ticTacToeBoard[0]);
    }
    for (i = 1; i < columns; i++)
    {
        if (ticTacToeBoard[i] == 0) /* 0 . The null/empty char is simply a value of zero */
        {
            printf("|   "); /* First Character */
        }
        else
        {
            printf("| %c ", ticTacToeBoard[i]); /* First Character. */
        }
    }
    printf("|\n");
}

/*
    Purpose: method that checks input is within range.
    Date: 13/10/2019 1:34am
    Imports: int placement[2], int rows, int columns
    Exports: accepted (boolean)
*/
int inAcceptableRange(int placement[2], int rows, int columns)
{
    int accepted = TRUE; /* Set to false if either invalid */
    if (placement[0] > columns-1)
    {
        printf("Cannot go to x:%d when only have %d columns.\nPlease enter a tile in the format x,y noting (0,0) is top left.\n",placement[0],columns);
        accepted = FALSE; /* Not Using ErrorPrint as its not a Error On The Program. */
    }
    else if (placement[1] > rows-1)
    {
        printf("Cannot go to y:%d when only have %d rows.\nPlease enter a tile in the format x,y noting (0,0) is top left.\n",placement[1],columns);
        accepted = FALSE; /* Not Using ErrorPrint as its not a Error On The Program. */
    }
    else if (placement[0] < 0)
    {
        printf("Invalid Input.\nPlease enter a tile in the format x,y noting (0,0) is top left.\n");
        accepted = FALSE; /* Not Using ErrorPrint as its not a Error On The Program. */
    }
    else if (placement[1] < 0)
    {
        printf("Invalid Input.\nPlease enter a tile in the format x,y noting (0,0) is top left.\n");
        accepted = FALSE; /* Not Using ErrorPrint as its not a Error On The Program. */
    }
    return accepted;
}
/*
    Purpose: wrapper method to check for victory.
    Date: 13/10/2019 1:34am
    Imports: char** ticTacToeBoard, int y, int x, int win, int rows, int columns, int player
    Exports: winBool (boolean)
*/
int checkForVictory(char** ticTacToeBoard, int y, int x, int win, int rows, int columns, int player)
{
    int winBool = FALSE;
    int currCount = 1;
    /* DIAGONAL CHECKS */
    currCount = checkDiagLeftBack(x,y,ticTacToeBoard,currCount,player,rows,columns);
    currCount = checkDiagLeftForward(x,y,ticTacToeBoard,currCount,player,rows,columns);
    /*printf("VAL: %d\n", currCount);*/
    if (currCount >= win)
    {
        winBool = TRUE;

    }
    else
    {
        currCount = 1;
        /*printf("ENTERING X:%d Y: %d\n",x,y);*/
        currCount = checkDiagRightBack(x,y,ticTacToeBoard,currCount,player,rows,columns);
        currCount = checkDiagRightForward(x,y,ticTacToeBoard,currCount,player,rows,columns);
        if (currCount >= win)
        {
            winBool = TRUE;

        }
        else
        { /* VERT CHECKS */
            currCount = 1;
            currCount = checkUp(x,y,ticTacToeBoard,currCount,player,rows,columns);

            currCount = checkDown(x,y,ticTacToeBoard,currCount,player,rows,columns);

            if (currCount >= win)
            {

                winBool = TRUE;
            }
            else
            {
                /* HORIZONTAL */
                currCount = 1;
                currCount = checkLeft(x,y,ticTacToeBoard,currCount,player,rows,columns);
                currCount = checkRight(x,y,ticTacToeBoard,currCount,player,rows,columns);
                if (currCount >= win)
                {

                    winBool = TRUE;
                }
            }
        }
    }
    return winBool;
}
/*
    Purpose: recursive method to checkleft for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkLeft(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x - 1) > -1)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y][x-1] == 'X')
            {
                currCount = checkLeft(x-1,y,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIrECTION LEFT\n");*/
            }
        }
        else
        {
            if (ticTacToeBoard[y][x-1] == 'O')
            {
                currCount = checkLeft(x-1,y,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkRight for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkRight(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x + 1) < columns)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y][x+1] == 'X')
            {
                currCount = checkRight(x+1,y,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIrECTION LEFT\n");*/
            }
        }
        else
        {
            if (ticTacToeBoard[y][x+1] == 'O')
            {
                currCount = checkRight(x+1,y,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkUp for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkUp(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((y - 1) > -1)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y-1][x] == 'X')
            {

                currCount = checkUp(x,y-1,ticTacToeBoard,currCount+1,player,rows,columns);

            }
        }
        else
        {
            if (ticTacToeBoard[y-1][x] == 'O')
            {

                currCount = checkUp(x,y-1,ticTacToeBoard,currCount+1,player,rows,columns);

                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkDown for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkDown(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((y + 1) < rows)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y+1][x] == 'X')
            {
                currCount = checkDown(x,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
            }
        }
        else
        {
            if (ticTacToeBoard[y+1][x] == 'O')
            {
                currCount = checkDown(x,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkDiagonalRight backwards for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkDiagRightBack(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x - 1) > -1 && (y + 1) < rows)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y+1][x-1] == 'X')
            {
                currCount = checkDiagRightBack(x-1,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIrECTION LEFT\n");*/
            }
        }
        else
        {
            if (ticTacToeBoard[y+1][x-1] == 'O')
            {
                currCount = checkDiagRightBack(x-1,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkDiagonalRight forward for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkDiagRightForward(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x + 1) < columns && (y - 1) > -1)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y-1][x+1] == 'X')
            {
                currCount = checkDiagRightForward(x+1,y-1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIrECTION LEFT\n");*/
            }
        }
        else
        {
            if (ticTacToeBoard[y-1][x+1] == 'O')
            {
                currCount = checkDiagRightForward(x+1,y-1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkDiagonalLeft forward for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkDiagLeftForward(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x + 1) < columns && (y + 1) < rows)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y+1][x+1] == 'X')
            {
                currCount = checkDiagLeftForward(x+1,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
            }
        }
        else
        {
            if (ticTacToeBoard[y+1][x+1] == 'O')
            {
                currCount = checkDiagLeftForward(x+1,y+1,ticTacToeBoard,currCount+1,player,rows,columns);
            }
        }
    }
    return currCount;
}
/*
    Purpose: recursive method to checkDiagonalLeft backward for count
    Date: 13/10/2019 1:34am
    Imports: int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns
    Exports: currCount.
*/
int checkDiagLeftBack(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns)
{
    if ((x - 1) > -1 && (y - 1) > -1)
    {
        if (player == 0)
        {
            if (ticTacToeBoard[y-1][x-1] == 'X')
            {
                currCount = checkDiagLeftBack(x-1,y-1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIrECTION LEFT\n");*/
            }
        }
        else
        {
            if (ticTacToeBoard[y-1][x-1] == 'O')
            {
                currCount = checkDiagLeftBack(x-1,y-1,ticTacToeBoard,currCount+1,player,rows,columns);
                /*printf("FOUND DIRECTION LEFT\n");*/
            }
        }
    }
    return currCount;
}
