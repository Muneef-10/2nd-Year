#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char stack[], char value, int *top)
{
    (*top)++;
    stack[*top] = value;
}

void pop(char stack[], int *top)
{
    if (*top == -1)
    {
        return;
    }
    printf("%c", stack[*top]);
    (*top)--;
}

void Reversing_By_Recursion(char string[], int index)
{
    if (string[index] == '\0')
    {
        return;
    }
    Reversing_By_Recursion(string, index + 1);
    printf("%c", string[index]);
}

void Reversing_without_Recursion(char string[], char stack[], int *top)
{
    int i = 0;
    while (string[i] != '\0')
    {
        push(stack, string[i], top);
        i++;
    }

    printf("Reversed String: ");
    while (*top != -1)
    {
        pop(stack, top);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        char string[100];
        int top = -1;

        printf("Enter the string: ");
        fgets(string, 100, stdin);

        string[strcspn(string, "\n")] = '\0';

        int size = strlen(string);
        char stack[size];
        int choice;

        printf("Enter [1] for Reversing the String Using Recursion\n");
        printf("Enter [2] for Reversing the String without Using Recursion\n");
        printf("Enter [3] to Exit the Program\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            printf("Reversed String: ");
            Reversing_By_Recursion(string, 0);
            printf("\n");
        }
        else if (choice == 2)
        {
            Reversing_without_Recursion(string, stack, &top);
        }
        else if (choice == 3)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}