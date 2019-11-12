#ifndef GAME
#define GAME
void startGame(board* gameBoard);
void displayBoard(char** ticTacToeBoard, int rows, int columns);
void printBorder(char chosenChar, int lineLength);
void printRow(char* ticTacToeBoard, int columns);
void initRow(char* row, int columns);
void nextTurn(int player, char** ticTacToeBoard, int rows, int columns, int win, int currTurn, linkedList* currGame);
int inAcceptableRange(int placement[2], int rows, int columns);
int checkDiagLeftBack(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkDiagLeftForward(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkForVictory(char** ticTacToeBoard, int y, int x, int win, int rows, int columns, int player);
int notTaken(char** ticTacToeBoard, int placement[2]);
int checkDiagRightForward(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkDiagRightBack(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkUp(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkDown(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkLeft(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
int checkRight(int x, int y, char** ticTacToeBoard, int currCount, int player, int rows, int columns);
void cleanUp(char** ticTacToeBoard, int rows, int columns);
#endif
