#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;
int tempCount = 1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void generateTAC(char expr[])
{
    char op1, op2, op;
    char temp[10];
    int i;

    printf("\nThree Address Code:\n");

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (isalnum(expr[i]))
        {
            push(expr[i]);
        }
        else if (expr[i] == '+' || expr[i] == '-' ||
                 expr[i] == '*' || expr[i] == '/')
        {
            op = expr[i];

            op2 = pop();
            op1 = pop();

            sprintf(temp, "t%d", tempCount++);

            printf("%s = %c %c %c\n",
                   temp, op1, op, op2);

            push(temp[1]);
        }
    }
}

int main()
{
    char expr[100];

    printf("Enter postfix expression: ");
    scanf("%s", expr);

    generateTAC(expr);

    return 0;
}