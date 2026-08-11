#include <stdio.h>
#include <ctype.h>

int main() {
    char ch, token[100];
    int i = 0;

    printf("Enter C Program (Press Ctrl+Z in Windows / Ctrl+D in Linux to end):\n");

    while ((ch = getchar()) != EOF) {

        // Ignore spaces, tabs and new lines
        if (ch == ' ' || ch == '\t' || ch == '\n')
            continue;

        // Ignore comments
        if (ch == '/') {
            char next = getchar();

            // Single-line comment
            if (next == '/') {
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }

            // Multi-line comment
            else if (next == '*') {
                char prev = 0;
                while ((ch = getchar()) != EOF) {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
                continue;
            }

            // '/' is an operator
            else {
                printf("Operator : /\n");
                ungetc(next, stdin);
                continue;
            }
        }

        // Identifier or Keyword
        if (isalpha(ch) || ch == '_') {
            i = 0;
            token[i++] = ch;

            while (isalnum(ch = getchar()) || ch == '_')
                token[i++] = ch;

            token[i] = '\0';
            printf("Identifier : %s\n", token);

            if (ch != EOF)
                ungetc(ch, stdin);
        }

        // Constant
        else if (isdigit(ch)) {
            i = 0;
            token[i++] = ch;

            while (isdigit(ch = getchar()))
                token[i++] = ch;

            token[i] = '\0';
            printf("Constant : %s\n", token);

            if (ch != EOF)
                ungetc(ch, stdin);
        }

        // Operators
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '=' || ch == '<' || ch == '>') {
            printf("Operator : %c\n", ch);
        }
    }

    return 0;
}