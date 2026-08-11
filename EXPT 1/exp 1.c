#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][20] = {
    "int", "float", "char", "double", "if", "else",
    "while", "for", "return", "void", "break", "continue"
};

int isKeyword(char str[]) {
    int i;
    for(i = 0; i < 12; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[1000], token[100];
    int i = 0, j;

    printf("Enter C Program (End with ~):\n");

    j = 0;
    while((input[j] = getchar()) != '~') {
        j++;
    }
    input[j] = '\0';

    while(input[i] != '\0') {

        // Ignore spaces, tabs, new lines
        if(input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            i++;
            continue;
        }

        // Ignore single-line comments
        if(input[i] == '/' && input[i+1] == '/') {
            while(input[i] != '\n' && input[i] != '\0')
                i++;
            continue;
        }

        // Ignore multi-line comments
        if(input[i] == '/' && input[i+1] == '*') {
            i += 2;
            while(!(input[i] == '*' && input[i+1] == '/') && input[i] != '\0')
                i++;
            i += 2;
            continue;
        }

        // Identifier or Keyword
        if(isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while(isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if(isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);
        }

        // Constant
        else if(isdigit(input[i])) {
            j = 0;
            while(isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("%s --> Constant\n", token);
        }

        // Operators
        else if(strchr("+-*/=%<>!&|", input[i])) {
            printf("%c --> Operator\n", input[i]);
            i++;
        }

        else {
            i++;
        }
    }

    return 0;
}