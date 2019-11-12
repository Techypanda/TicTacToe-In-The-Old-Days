/*
    Author: Jonathan Wright 19779085
    Purpose: This is a C file for common methods across all c files.
    Date: 7/10/2019, 10:30pm
*/

#include "commonlib.h"
#include <stdlib.h>
#include <stdio.h>

/*
    IMPORTS: char* error (message to output), int errorCode (error code associated)
    EXPORTS: none
    PURPOSE: To output a severe error.
    DATE: 7/10/2019, 10:30pm
*/
void errorPrint(char* error)
{
    printf("Error: %s\n", error);
}

/*
    IMPORTS: char* error (message to output)
    EXPORTS: none
    PURPOSE: To output a minor error.
    DATE: 7/10/2019, 10:30pm
*/
void minorError(char* error)
{
    printf("Minor Error (Program Will Continue): %s\n", error);
}
