#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Tree
{
    char val;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree tree;
struct OperandStack
{
    tree *arr[100];
    int top;
};
typedef struct OperandStack operandStack;
struct OperatorStack
{
    char arr[100];
    int top;
};
typedef struct OperatorStack operatorStack;

void pushOperand(operandStack *s, tree *val)
{
    s->arr[++(s->top)] = val;
}

void popOperand(operandStack *s)
{
    (s->top)--;
}

void pushOperator(operatorStack *s, char val)
{
    s->arr[++(s->top)] = val;
}

void popOperator(operatorStack *s)
{
    (s->top)--;
}

char peekOperator(operatorStack *s)
{
    return s->arr[s->top];
}
tree *peekOperand(operandStack *s)
{
    return s->arr[s->top];
}

tree *createNode(char val)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
bool isOperand(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return true;
    }
    return false;
}
tree *insert(tree *root, char *vals, int n, int i, operandStack *stk, operatorStack *stx)
{
    for (int i = 0; i < n; i++)
    {
        char x = vals[i];
        if (isOperand(x))
        {
            pushOperand(stk, createNode(x));
        }
        else
        {
            if (x == '(')
            {
                pushOperator(stx, x);
            }
            else if (x == ')')
            {
                while (peekOperator(stx) != '(')
                {
                    tree *temp = createNode(peekOperator(stx));
                    popOperator(stx);
                    temp->right = peekOperand(stk);
                    popOperand(stk);
                    temp->left = peekOperand(stk);
                    popOperand(stk);
                    pushOperand(stk, temp);
                }
                popOperator(stx);
            }
            else
            {
                while (stx->top != -1 && peekOperator(stx) != '(' && (precedence(peekOperator(stx)) > precedence(x) || (precedence(peekOperator(stx)) == precedence(x) && x != '^')))
                {
                    tree *temp = createNode(peekOperator(stx));
                    popOperator(stx);
                    temp->right = peekOperand(stk);
                    popOperand(stk);
                    temp->left = peekOperand(stk);
                    popOperand(stk);
                    pushOperand(stk, temp);
                }
                pushOperator(stx, x);
            }
        }
    }
    while (stx->top != -1)
    {
        tree *temp = createNode(peekOperator(stx));
        popOperator(stx);
        temp->right = peekOperand(stk);
        popOperand(stk);
        temp->left = peekOperand(stk);
        popOperand(stk);
        pushOperand(stk, temp);
    }
    root = peekOperand(stk);
    return root;
}

void inOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->val);
    inOrder(root->right);
}

void postOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->val);
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        char exp[100];
        fgets(exp, 100, stdin);
        int n = strlen(exp);
        exp[n - 1] = '\0';
        n--;
        operandStack *stk = (operandStack *)malloc(sizeof(operandStack));
        stk->top = -1;
        operatorStack *stx = (operatorStack *)malloc(sizeof(operatorStack));
        stx->top = -1;
        tree *root = NULL;
        root = insert(root, exp, n, 0, stk, stx);
        printf("Postfix: ");
        postOrder(root);
        printf("\n");
        free(stk);
        free(stx);
        free(root);
    }
    return 0;
}
