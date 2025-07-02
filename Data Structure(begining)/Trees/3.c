#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left,*right;
}node;
node *create(int val)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->right=NULL;
    tmp->left=NULL;
    tmp->data=val;
    return tmp;
}
node *insert(node *root,int val)
{
    if(root==NULL) return create(val);
    if(root->data==val) return root;
    if(root->data > val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
node *getsucc(node *root)
{
    root=root->right;
    while(root!=NULL && root->left!=NULL) root=root->left;
    return root;
}
node* dlt(node *root,int val)
{
    if(root==NULL)
    return root;
    if(root->data > val) root->left=dlt(root->left,val);
    else if(root->data < val) root->right=dlt(root->right,val);
    else
    {
        if(root->left==NULL)
        {
            node *tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL)
        {
            node *tmp=root->left;
            free(root);
            return tmp;
        }
        else
        {
            node *succ=getsucc(root);
            root->data=succ->data;
            root->right=dlt(root->right,val);
        }
        return root;
    }
}
void main()
{
    node *root=NULL;
    root=insert(root,10);
    root=insert(root,12);
    root=insert(root,8);
    root=insert(root,6);
    root=insert(root,17);
    root=insert(root,14);
    root=insert(root,3);
    printf("Elements of trees in inorder: ");
    inorder(root);
    root=dlt(root,12);
    root=dlt(root,17);
    printf("\nElements of trees in inorder after deletion: ");
    inorder(root);
}