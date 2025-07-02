#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}node;
node *create(int val)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
node *insert(node *root,int val)
{
    if(root==NULL) return create(val);
    node *queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp->left==NULL)
        {
            tmp->left=create(val);
            break;
        }
        else
        {
            queue[rear++]=tmp->left;
        }
        if(tmp->right==NULL)
        {
            tmp->right=create(val);
            break;
        }
        else
        {
            queue[rear++]=tmp->right;
        }
    }
    return root;
    
}
void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void main()
{
    node *root=NULL;
    root=create(2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
}