/*
    AUTHOR: Jonathan Wright
    DATE: 7/10/2019
    PURPOSE: This contains things i deem to be "common" throughout all the files
    this includes things such as typedefs, definitions (True/False), etc.
    No Functions (no attached .c file) are included this is purely declarative.
*/

#ifndef COMMONLIB
#define COMMONLIB
#define TRUE 1
#define FALSE 0
void errorPrint(char* error);
void minorError(char* error);
#endif
