#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}node;
node *create()
{
    int val;
    printf("Enter element: ");
    scanf("%d",&val);
    node* tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
node *insert(node *root)
{
    if(root==NULL) return create();
    node *queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp->left==NULL)
        {
            tmp->left=create();
            break;
        }
        else
        {
            queue[rear++]=tmp->left;
        }
        if(tmp->right==NULL)
        {
            tmp->right=create();
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
node *GetDeepRightNode(node *root)
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
void DeleteDeepRightNode(node* root,node *dltnode)
{
    node *queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp==dltnode)
        {
            tmp=NULL;
            free(tmp);
            return ;
        }
        if(tmp->left!=NULL)
        {
            if(tmp->left==dltnode)
            {
                tmp->left=NULL;
                free(dltnode);
                return ;
            }
            else
            {
                queue[rear++]=tmp->left;
            }
        }
        if(tmp->right!=NULL)
        {
            if(tmp->right==dltnode)
            {
                tmp->right=NULL;
                free(dltnode);
                return ;
            }
            else
            {
                queue[rear++]=tmp->right;
            }
        }

    }
}
void deletenode(node **root,int dltval)
{
    if((*root)==NULL)
    {
        printf("No tree present\n");
        return ;
    }
    if((*root)->right==NULL && (*root)->left==NULL)
    {
        if((*root)->data==dltval)
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
    node *queue[50];
    int front =0,rear=0;
    queue[rear++]=(*root);
    node *keynode=NULL;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp->data==dltval)
        {
            keynode=tmp;
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
    if(keynode!=NULL)
    {
        node *deepnode=GetDeepRightNode(*root);
        keynode->data=deepnode->data;
        DeleteDeepRightNode(*root,deepnode);
    }
    else
    {
        printf("Value not found\n");
    }
}
int height(node *root)
{
    if(root==NULL) return -1;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(lheight>rheight) return lheight+1;
    else return rheight+1;
}
bool Issearch(node *root,int val)
{
    if(root==NULL) return false;
    if(root->data==val) return true;
    node *queue[50];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *tmp=queue[front++];
        if(tmp->data==val) return true;
        if(tmp->left!=NULL) queue[rear++]=tmp->left;
        if(tmp->right!=NULL) queue[rear++]=tmp->right;
    }
    return false;
}
int size(node *root)
{
    if(root==NULL) return 0;
    int lsize=size(root->left);
    int rsize=size(root->right);
    
    return lsize+rsize+1;
}
void main()
{
    node *root=NULL;
    int choice;
    do
    {
        printf("Press [1] to create tree\n");
        printf("Press [2] to insert in tree\n");
        printf("Press [3] to print in inorder\n");
        printf("Press [4] to delete\n");
        printf("Press [5] to find height\n");
        printf("Press [6] to search element\n");
        printf("Press [7] to find size\n");
        printf("Press [0] to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit..\n");
                break;
            case 1:
                root=create();
                break;
            case 2:
                root=insert(root);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
            {   
                int dltval;
                printf("Enter value to delete: ");
                scanf("%d",&dltval);
                deletenode(&root,dltval);
                break;
            }
            case 5:
                printf("Height of tree is: %d\n",height(root));
                break;
            case 6:
            {
                int val;
                printf("Enter value to search: ");
                scanf("%d",&val);
                if(Issearch(root,val)) printf("%d is present in tree\n",val);
                else printf("%d is not present in tree\n",val);
                break;
            }
            case 7:
                printf("Size of binary tree is: %d\n",size(root));
                break;
            default:
                printf("Invalid input,Try again..");
                break;
        }
    } while (choice!=0);
}