#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

struct treeNode {
    char val;
    struct treeNode* left;
    struct treeNode* right;
};
typedef struct treeNode treeNode;

struct charStack {
    int top;
    char* arr;
};
typedef struct charStack charStack;

struct treeNodeStack {
    int top;
    treeNode** arr;
};
typedef struct treeNodeStack treeNodeStack;

void pushChar(charStack* stk, char c) {
    stk->arr[++(stk->top)] = c;
}
void popChar(charStack* stk) {
    (stk->top)--;
}
char topChar(charStack* stk) {
    return stk->arr[stk->top];
}
treeNode* toptreeNode(treeNodeStack* stk) {
    return stk->arr[stk->top];
}
void pushtreeNode(treeNodeStack* stk, treeNode* r) {
    stk->arr[++(stk->top)] = r;
}
void poptreeNode(treeNodeStack* stk) {
    (stk->top)--;
}

treeNodeStack* createtreeNodeStack() {
    treeNodeStack* stk = (treeNodeStack*)malloc(sizeof(treeNodeStack));
    stk->top = -1;
    stk->arr = (treeNode**)malloc(sizeof(treeNode*) * SIZE);
    return stk;
}
charStack* createCharStack() {
    charStack* stk = (charStack*)malloc(sizeof(charStack));
    stk->top = -1;
    stk->arr = (char*)malloc(sizeof(char) * SIZE);
    return stk;
}
treeNode* createTreeNode(char c) {
    treeNode* new_node = (treeNode*)malloc(sizeof(treeNode));
    new_node->val = c;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bool isEmptyCharStack(charStack* stk) {
    return stk->top == -1;
}

bool isOperand(char ch) {
    return ch >= 'a' && ch <= 'z';
}

int pres(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }
}
void postorder(treeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->val);
}

int main() {
    int t;
    printf("Enter test cases: ");
    scanf("%d",&t);
    getchar();
    while(t--){
        char s[SIZE];
        gets(s);
        int l = strlen(s);
    
        charStack* stk1 = createCharStack();
        treeNodeStack* stk2 = createtreeNodeStack();
    
        for (int i = 0; i < l; i++) {
            if (s[i] == '(') {
                pushChar(stk1, '(');
            } else if (s[i] == ')') {
                while (topChar(stk1) != '(') {
                    treeNode* r1 = toptreeNode(stk2);
                    poptreeNode(stk2);
                    treeNode* r2 = toptreeNode(stk2);
                    poptreeNode(stk2);
    
                    treeNode* r = createTreeNode(topChar(stk1));
                    popChar(stk1);
    
                    r->right = r1;
                    r->left = r2;
    
                    pushtreeNode(stk2, r);
                }
                popChar(stk1);
            } else if (isOperand(s[i])) {
                treeNode* r = createTreeNode(s[i]);
                pushtreeNode(stk2, r);
            } else {
                while (!isEmptyCharStack(stk1) && topChar(stk1) != '(' && ((pres(s[i]) < pres(topChar(stk1))) || (pres(s[i]) == pres(topChar(stk1)) && s[i] != '^'))) {
                        treeNode* r1 = toptreeNode(stk2);
                        poptreeNode(stk2);
                        treeNode* r2 = toptreeNode(stk2);
                        poptreeNode(stk2);
    
                        treeNode* r = createTreeNode(topChar(stk1));
                        popChar(stk1);
    
                        r->right = r1;
                        r->left = r2;
    
                        pushtreeNode(stk2, r);
                }
                pushChar(stk1, s[i]);
            }
        }
    
        while (!isEmptyCharStack(stk1)) {
            treeNode* rightNode = toptreeNode(stk2);
            treeNode* r1 = toptreeNode(stk2);
            poptreeNode(stk2);
            treeNode* r2 = toptreeNode(stk2);
            poptreeNode(stk2);
    
            treeNode* r = createTreeNode(topChar(stk1));
            popChar(stk1);
            r->right = r1;
            r->left = r2;
    
            pushtreeNode(stk2, r);
        }
        treeNode* root = toptreeNode(stk2);
        postorder(root);
        printf("\n");
    }
    return 0;
}
