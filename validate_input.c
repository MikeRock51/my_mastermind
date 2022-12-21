#include "mastermind.h"
/*
* validate_input - Checks if user input is apt
* @input: input to check
* Return: 0 if input is apt or -1 otherwise
*/
int validate_input(char *input)
{
    int i = 0, len = strlen(input);
    char c;
    while (i < len - 1)
    {
        c = (int)input[i];
        if (c >= 48 && c <= 56)
            i++;
        else
            return (-1);
    }
    return(0);
}