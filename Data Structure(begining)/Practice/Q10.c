// Given an empty stack, design an algorithm and a program to reverse a string using this stack (with recursion).

#include <stdio.h>
#include <string.h>

void push(char st[], int *top, char ch) {
    (*top)++;
    st[*top] = ch;
}

char pop(char st[], int *top) {
    char ch = st[*top];
    (*top)--;
    return ch;
}

void reverse(char st[], int *top, char str[], int index) {
    if (str[index] == '\0') return;
    str[index] = pop(st, top);
    reverse(st,top,str,index+1);
}

int main() {
    int top = -1;
    char st[50];
    char str[50];
    printf("Enter string: ");
    scanf("%[^\n]s", str);
    int l = strlen(str);
    for (int i = 0; i < l; i++)
    {
        push(st,&top,str[i]);
    }
    reverse(st, &top, str, 0);
    printf("Reversed string: %s\n", str);
    return 0;
}