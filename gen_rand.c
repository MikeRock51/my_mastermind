#include "mastermind.h"

char *gen_rand(void)
{
    int random[9];
    char *str = malloc(sizeof(char *) * 4);
    int i, j, tmp;
    for (i = 0; i < 9; i++)
        random[i] = i;
    srand(time(NULL));
    for (i = 0; i < 4; i++)
    {
        j = rand() % 9, tmp = random[i];
        random[i] = random[j], random[j] = tmp;
    }
    sprintf(str, "%d%d%d%d", random[0], random[1], random[2], random[3]);
    // ran = atoi(str);
    return (str);
}