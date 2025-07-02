#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Tree
{
    int val;
    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree tree;

tree *insertBST(tree *root, int val)
{
    if (val == -1)
    {
        return NULL;
    }
    if (root == NULL)
    {
        tree *temp = (tree *)malloc(sizeof(tree));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (val <= root->val)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int findMaxNodesLvl(tree *root, int *maxNodes)
{
    if (root == NULL)
    {
        return 0;
    }
    tree *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    int maxLvl = 0;
    int lvl = 1;
    while (front != rear)
    {
        int count = rear - front;
        if (count > *maxNodes)
        {
            *maxNodes = count;
            maxLvl = lvl;
        }
        while (count--)
        {
            tree *temp = q[front++];
            if (temp->left != NULL)
            {
                q[rear++] = temp->left;
            }
            if (temp->right != NULL)
            {
                q[rear++] = temp->right;
            }
        }
        lvl++;
    }
    return maxLvl;
}

void display(tree* root) {
    if (!root) return;
    tree** queue = (tree**)malloc(100 * sizeof(tree));
    int front = 0, rear = 0;
    queue[rear++] = root;
    printf("Tree: ");
    while (front < rear) {
        tree* current = queue[front++];
        printf("%d ", current->val);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
    free(queue);
}

int main()
{
    bool p = true;
    tree *root = NULL;

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        tree *temp = insertBST(root, x);
        if (temp != NULL)
        {
            root = temp;
        }
    }
    printf("BST:");
    display(root);
    int maxNodes = 0;
    int maxLvl = findMaxNodesLvl(root, &maxNodes);
    printf("Level %d has maximum number of nodes: %d\n", maxLvl, maxNodes);
    return 0;
}
