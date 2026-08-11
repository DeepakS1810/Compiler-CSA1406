#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, newlines = 0;

    printf("Enter the text (press Ctrl+D to stop):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t')
            spaces++;
        else if (ch == '\n')
            newlines++;
    }

    printf("\nNumber of whitespaces: %d", spaces);
    printf("\nNumber of newline characters: %d", newlines);

    return 0;
}