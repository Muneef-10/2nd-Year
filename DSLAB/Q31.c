/* Design an algorithm to implement binary trees. Write a program which implements following basic operations on binary tree:
a) CreateTree() - creates a root node
b) InsertNode() - insert a node in tree
c) DeleteNode() - delete a node from tree
d) FindHeight() - find the height of tree
e) FindSize() - find number of nodes in tree
f) Search() - search whether given specific element present in tree or not. */

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
}node;
node *create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->key=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
void insert(node **root)
{
    node *tmp=create();
    if(root==NULL)
    {
        (*root)==create();
        return ;
    }
    node *queue[100];
    int front=0,rear=0;
    queue[rear++]=*root;
    while (front < rear)
    {
        node *curr=queue[front++];
        if(curr->left==NULL)
        {
            curr->left=tmp;
            return ;
        }
        else queue[rear++]=curr->left;
        if(curr->right==NULL)
        {
            curr->right=tmp;
            return ;
        }
        else queue[rear++]=curr->right;
    }
    
}
void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
void main()
{
    node *root;
    int choice;
    do
    {
        printf("\nPress [1] to create a tree\n");
        printf("Press [2] to insert a node\n");
        printf("Press [3] to display in inorder\n");
        printf("Press [4] to delete a node \n");
        printf("Press [5] to find height\n");
        printf("Press [6] to find size(numbe of nodes in tree\n");
        printf("Press [7] to search an element\n");
        printf("Press [0] to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                root=create();
                break;
            case 2:
                insert(&root);
                break;
            case 3:
                inorder(root);
                break;
        }
    } while (choice!=0);   
}