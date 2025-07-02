/* Design an algorithm to implement binary trees. Write a program which implements following basic operations on binary tree:
a) CreateTree() - creates a root node
b) InsertNode() - insert a node in tree
c) DeleteNode() - delete a node from tree
d) FindHeight() - find the height of tree
e) FindSize() - find number of nodes in tree
f) Search() - search whether given specific element present in tree or not. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
}node;
node *create()
{
    int val;
    printf("Enter value: ");
    scanf("%d",&val);
    node *tmp=(node*)malloc(sizeof(node));
    tmp->key=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
void insert(node **root)
{
    node *tmp=create();
    if(*root==NULL)
    {
        (*root)=tmp;
        return;
    }    
    node *queue[50];
    int front=0,rear=0;
    queue[rear++]=(*root);
    while(front<rear)
    {
        node *curr=queue[front++];
        if(curr->left==NULL)
        {
            curr->left=tmp;
            return;
        }
        else queue[rear++]=curr->left;
        if(curr->right==NULL)
        {
            curr->right=tmp;
            return;
        }
        else queue[rear++]=curr->right;
    }
}
void inorder(node *root)
{
    if(root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
node *getdeepest(node *root)
{
    node *queue[50],*tmp;
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        tmp=queue[front++];
        if(tmp->left!=NULL)
        {
            queue[rear++]=tmp->left;
        }
        if(tmp->right!=NULL)
        {
            queue[rear++]=tmp->right;
        }
    }
    return tmp;
}
void deletedeepest(node *root,node *dltnode)
{
    node *queue[50],*tmp;
    int front =0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        tmp=queue[front++];
        if(tmp==dltnode)
        {
            tmp=NULL;
            free(tmp);
            return;
        }
        if(tmp->left!=NULL)
        {
            if(tmp->left==dltnode)
            {
                tmp->left=NULL;
                free(dltnode);
                return;
            }
            else queue[rear++]=tmp->left;
        }
        if(tmp->right!=NULL)
        {
            if(tmp->right==dltnode)
            {
                tmp->right=NULL;
                free(dltnode);
                return;
            }
            else queue[rear++]=tmp->right;
        }
    }

}
void deletenode(node **root,int val)
{
    if((*root)==NULL)return ;
    if((*root)->right==NULL && (*root)->left==NULL)
    {
        if((*root)->key==val)
        {
            (*root)=NULL;
            free(*root);
            return ;
        }
        else
        {
            printf("Value not found\n");
            return ;
        }
    } 
    node *queue[50],*tmp,*keynode=NULL;
    int front=0,rear=0;
    queue[rear++]=(*root);
    while(front<rear)
    {
        tmp=queue[front++];
        if(tmp->key==val)
        {
            keynode=(tmp);
            break;
        }
        if(tmp->left!=NULL)
        {
            queue[rear++]=tmp->left;
        }
        if(tmp->right!=NULL)
        {
            queue[rear++]=tmp->right;
        }
    }
    if(keynode==NULL)
    {
        printf("Element not found\n");
        return ;
    }
    node *deep=getdeepest(*root);
    keynode->key=deep->key;
    deletedeepest(*root,deep);

}
bool Issearch(node *root,int val)
{
    if(root==NULL) return false;
    if(root->key==val) return true;
    node *queue[50];
    int front =0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp->key==val) return true;
        if(tmp->left!=NULL) queue[rear++]=tmp->left;
        if(tmp->right!=NULL) queue[rear++]=tmp->right;
    }
    return false;
}
int height(node *root)
{
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left+1;
    else  return right+1;
}
int size(node *root)
{
    if(root==NULL) return 0;
    int left=size(root->left);
    int right=size(root->right);
    return left+right+1;
}
void main()
{
    node *root=NULL;
    int choice;
    do
    {
        printf("Press [1] to create tree\n");
        printf("Press [2] to insert element in tree\n");
        printf("Press [3] to display tree\n");
        printf("Press [4] to delete node in tree\n");
        printf("Press [5] to find height of tree\n");
        printf("Press [6] to find size of tree\n");
        printf("Press [7] to search element in tree\n");
        printf("Press [0] to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            printf("Exit..\n");
            break;
        case 1:
            root=create();
            break;        
        case 2:
            insert(&root);
            break;        
        case 3:
            inorder(root);
            printf("\n");
            break;       
        case 4:
        {
            int v;
            printf("Enter value to delete: ");
            scanf("%d",&v);
            deletenode(&root,v);
            break;
        } 
        case 5:
            printf("Height is %d",height(root));
            break;
        case 6:
            printf("Size is %d",size(root));
            break;
        case 7:
        {
            int v;
            printf("Enter value to search: ");
            scanf("%d",&v);
            if(Issearch(root,v)) printf("Element found\n");
            else printf("Element not found\n");
            break;
        } 
            
        default:
            printf("Invalid input, try again\n");
            break;
        }
    } while (choice!=0);
    

}