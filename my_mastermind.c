#include <unistd.h>
#include "mastermind.h"

int main(int ac, char *av[])
{
    char *guess = malloc(sizeof(char*)), *code = malloc(sizeof(char *));
    int attempts = 0, i, j, /*rand_code,*/ misplaced, placed;
    size_t rd;
    if (ac > 1)
    {
        if (strcmp(av[1],"-c") == 0)
            code = strdup(av[2]);
        else if (strcmp(av[1], "-t") == 0)
            printf("You have %d attempts left", 10 - attempts);
    }
    else
        code = gen_rand()/*, itoa(code, rand_code)*/;
    printf("%s\n", PROMPT);
    while (attempts < 10)
    {   
        printf("Round %d\n", attempts);
        rd = read(STDIN_FILENO, guess, 5);
        
        if (rd != 0)
        {
            if (strncmp(code, guess, 4) == 0)
            {
                printf("Congratz! You did it!\n");
                return (0);
            }
            else if (rd != 5 || validate_input(guess) == -1)
            {
                printf("Wrong input!\n"), attempts++;
                continue;
            }
            else
            {
                i = 0, misplaced = 0, placed = 0;
                while (i < 4)
                {
                    j = 0;
                    if (code[i] == guess[i])
                    {
                        placed++, i++, j++;
                        continue;
                    }
                    while (j < 4)
                    {
                        if (code[j] == guess[i] && i != j)
                            misplaced++;
                        if (code[j] == guess[i] && i == j)
                            placed++;
                        j++;
                    }
                    i++;
                }
                printf("Well placed pieces: %d\n", placed), printf("Misplaced pieces: %d\n", misplaced);
                attempts++;
            }
        }
        else
            return (0);
    }
    printf("You are out of attempts\n");
    free(guess), free(code);
    return (0);
}