#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[20];
};

struct Symbol table[50];
int n = 0;

void insert()
{
    printf("Enter symbol name: ");
    scanf("%s", table[n].name);

    printf("Enter type: ");
    scanf("%s", table[n].type);

    n++;
    printf("Symbol inserted successfully.\n");
}

void search()
{
    char name[20];
    int i;

    printf("Enter symbol to search: ");
    scanf("%s", name);

    for (i = 0; i < n; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            printf("Symbol found: %s (%s)\n",
                   table[i].name, table[i].type);
            return;
        }
    }

    printf("Symbol not found.\n");
}

void display()
{
    int i;

    printf("\nSymbol Table\n");
    printf("Name\tType\n");

    for (i = 0; i < n; i++)
        printf("%s\t%s\n", table[i].name, table[i].type);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}