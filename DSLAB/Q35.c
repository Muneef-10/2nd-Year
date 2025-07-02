/*Q35. Design an algorithm and a program to convert binary search tree created in previous question into balanced BST. Also find maximum and minimum element from this balanced BST.*/
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

void inOrder(tree *root, int *vals, int *i)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, vals, i);
    vals[(*i)++] = root->val;
    inOrder(root->right, vals, i);
}

tree *balancedBst(int *vals, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    tree *curr = (tree *)malloc(sizeof(tree));
    curr->val = vals[mid];
    curr->left = balancedBst(vals, start, mid - 1);
    curr->right = balancedBst(vals, mid + 1, end);
    return curr;
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
    free(queue);
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int vals[n];
    printf("Enter element: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    tree *root = NULL;
    for (int i = 0; i < n; i++)
    {
        tree *temp = insertBST(root, vals[i]);
        if (temp != NULL)
        {
            root = temp;
        }
    }
    int sortedVals[n];
    int i = 0;
    inOrder(root, sortedVals, &i);
    // sortedVals[i] = -1;
    // int size = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (sortedVals[i] == -1)
    //     {
    //         size = i;
    //         break;
    //     }
    // }
    tree *newRoot = balancedBst(sortedVals, 0, n - 1);
    printf("Initial BST:");
    display(root);
    printf("\nBalanced BST:");
    display(newRoot);
    // printf("\nMaximum value: %d\n", maxVal(newRoot));
    // printf("Minimum value: %d\n", minVal(newRoot));
    return 0;
}





/*int minVal(tree *root)
{
    if (root == NULL)
    {
        return -1;
    }
    tree *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->val;
}

int maxVal(tree *root)
{
    if (root == NULL)
    {
        return -1;
    }
    tree *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}*/