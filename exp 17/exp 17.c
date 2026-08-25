#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char leading[3][MAX];
int count[3] = {0};

int indexOf(char ch)
{
    if (ch == 'E') return 0;
    if (ch == 'T') return 1;
    if (ch == 'F') return 2;
    return -1;
}

void addLeading(int i, char ch)
{
    int j;

    for (j = 0; j < count[i]; j++)
    {
        if (leading[i][j] == ch)
            return;
    }

    leading[i][count[i]++] = ch;
}

int main()
{
    /*
       Grammar:
       E -> E+T | T
       T -> T*F | F
       F -> (E) | id
    */

    /* LEADING(F) = { (, i } */
    addLeading(2, '(');
    addLeading(2, 'i');   // i represents id

    /* LEADING(T) = LEADING(F) U { * } */
    addLeading(1, '(');
    addLeading(1, 'i');
    addLeading(1, '*');

    /* LEADING(E) = LEADING(T) U { + } */
    addLeading(0, '(');
    addLeading(0, 'i');
    addLeading(0, '*');
    addLeading(0, '+');

    printf("LEADING Sets:\n\n");

    printf("LEADING(E) = { ");
    for (int i = 0; i < count[0]; i++)
        printf("%c ", leading[0][i]);
    printf("}\n");

    printf("LEADING(T) = { ");
    for (int i = 0; i < count[1]; i++)
        printf("%c ", leading[1][i]);
    printf("}\n");

    printf("LEADING(F) = { ");
    for (int i = 0; i < count[2]; i++)
        printf("%c ", leading[2][i]);
    printf("}\n");

    return 0;
}