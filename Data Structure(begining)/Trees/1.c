#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
}node;
node *newnode(int  val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->key=val;
    return tmp;
}
node *insert(node *root,int val)
{
    if(root==NULL)  return newnode(val);
    else
    {
        if(root->key > val)
        root->left=insert(root->left,val);
        else
        root->right=insert(root->right,val);
    }
}
void inorder(node *root)
{
    if(root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL) return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}
void main()
{
    node *root=NULL;
    root=insert(root,30);
    root=insert(root,50);
    root=insert(root,65);
    root=insert(root,75);
    root=insert(root,85);
    root=insert(root,100);
    root=insert(root,150);
    root=insert(root,170);
    root=insert(root,200);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
}
