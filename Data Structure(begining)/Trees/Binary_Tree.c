#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left,*right;
}node;
node *create()
{
    int x;
    printf("\nEnter element(-1 for no new node): ");
    scanf("%d",&x);
    if(x==-1) return NULL;
    node *newnode=(node *)malloc(sizeof(node));
    
    newnode->key=x;

    printf("Enter left child of %d:-",x);
    newnode->left=create();
    printf("Enter right child of %d:-",x);
    newnode->right=create();
    return newnode;
}
void inorder(node *root)
{
    if(root ==NULL) return;
    inorder(root->left);
    printf("%d ",root->key);    
    inorder(root->right);    
}
void main()
{
    node *root=NULL;
    root=create();
    inorder(root);
}