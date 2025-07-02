#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left,*right;
}node;
node *newnode(int item)
{
    node* tmp=(node*)malloc (sizeof(node));
    tmp->key=item;
    tmp->left=tmp->right=NULL;
    return tmp;
}
node *insertnode(node* root,int key)
{
    if(root==NULL) return newnode(key);
    if(root->key==key) return 0;
    if(root->key>key) root->left=insertnode(root->left,key);
    if(root->key<key) root->right=insertnode(root->right,key);
    return root;
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
int main()
{
    node *root=NULL;
    root=insertnode(root,10);
    root=insertnode(root,12);
    root=insertnode(root,17);
    root=insertnode(root,6);
    root=insertnode(root,32);
    root=insertnode(root,4);
    root=insertnode(root,25);
    inorder(root);
    return 0;
}