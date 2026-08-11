#include <stdio.h>

int main() {
    char ch;

    printf("Enter an operator: ");
    scanf("%c", &ch);

    switch(ch) {
        case '+':
            printf("'%c' is Addition Operator\n", ch);
            break;

        case '-':
            printf("'%c' is Subtraction Operator\n", ch);
            break;

        case '*':
            printf("'%c' is Multiplication Operator\n", ch);
            break;

        case '/':
            printf("'%c' is Division Operator\n", ch);
            break;

        default:
            printf("'%c' is Not an Arithmetic Operator\n", ch);
    }

    return 0;
}