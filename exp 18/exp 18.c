#include <stdio.h>

#define MAX 20

char trailing[3][MAX];
int count[3] = {0};

void addTrailing(int index, char ch)
{
    int i;

    for (i = 0; i < count[index]; i++)
    {
        if (trailing[index][i] == ch)
            return;
    }

    trailing[index][count[index]++] = ch;
}

int main()
{
    /*
        Grammar:
        E -> E + T | T
        T -> T * F | F
        F -> ( E ) | id
    */

    /*
        TRAILING(F) = { ), i }
        where i represents id
    */
    addTrailing(2, ')');
    addTrailing(2, 'i');

    /*
        TRAILING(T) = TRAILING(F) U { * }
    */
    addTrailing(1, ')');
    addTrailing(1, 'i');
    addTrailing(1, '*');

    /*
        TRAILING(E) = TRAILING(T) U { + }
    */
    addTrailing(0, ')');
    addTrailing(0, 'i');
    addTrailing(0, '*');
    addTrailing(0, '+');

    printf("TRAILING Sets:\n\n");

    printf("TRAILING(E) = { ");
    for (int i = 0; i < count[0]; i++)
        printf("%c ", trailing[0][i]);
    printf("}\n");

    printf("TRAILING(T) = { ");
    for (int i = 0; i < count[1]; i++)
        printf("%c ", trailing[1][i]);
    printf("}\n");

    printf("TRAILING(F) = { ");
    for (int i = 0; i < count[2]; i++)
        printf("%c ", trailing[2][i]);
    printf("}\n");

    return 0;
}