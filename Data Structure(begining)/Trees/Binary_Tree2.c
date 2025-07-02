#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left,*right;
}node;
node *create(int val)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->key=val;
    newnode->left=NULL;
    newnode->right=NULL;
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
    node *firstnode=create(2);
    node *secondnode=create(3);
    node *thirdnode=create(4);
    node *fourthnode=create(5);

    firstnode->left=secondnode;
    firstnode->right=thirdnode;
    secondnode->left=fourthnode;
    inorder(firstnode);
}