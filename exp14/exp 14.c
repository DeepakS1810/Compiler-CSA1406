#include <stdio.h>
#include <string.h>

int main() {
    char exp[50];
    char op[] = {'/', '*', '+', '-'};
    int i, j, k, temp = 1;

    printf("Enter the expression: ");
    scanf("%s", exp);

    printf("\nThree Address Code:\n");

    for (k = 0; k < 4; k++) {
        for (i = 0; exp[i] != '\0'; i++) {
            if (exp[i] == op[k]) {
                printf("t%d = %c %c %c\n", temp, exp[i - 1], exp[i], exp[i + 1]);

                // Replace the operation with temporary variable
                exp[i - 1] = 't';
                exp[i] = temp + '0';
                for (j = i + 1; exp[j] != '\0'; j++)
                    exp[j] = exp[j + 2];

                temp++;
                i = -1; // Restart scanning
            }
        }
    }

    printf("\nFinal Result: %s\n", exp);

    return 0;
}