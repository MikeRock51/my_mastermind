#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_

#define PROMPT "Will you find the secret code?\nPlease enter a valid guess"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>


void get_guess();
void itoa(char str[], int num);
char *gen_rand(void);
int concat_int (int x, int y);
int validate_input(char *input);
// void handle_sig(int sig);

#endif