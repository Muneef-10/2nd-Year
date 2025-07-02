#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int key;
    struct Node *left,*right;
}node;
node *newnode(int val)
{
    
    node *root=(node*)malloc(sizeof(node));
    root->key=val;
    root->left=root->right=NULL;
    return root;
}
node *insert(node *root,int val)
{
    if(root==NULL) return newnode(val);
    if(root->key==val) return root;
    if(root->key > val) root->left=insert(root->left,val);
    else root->right= insert(root->right,val);
    return root;
}
void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
bool Issearch(node *root,int search)
{
    if(root==NULL) return false;
    if(root->key==search) return true;
    if(root->key > search) Issearch(root->left,search);
    else Issearch(root->right,search);
}
node *InOrderPredecessor(node *root)
{
    if(root==NULL || root->left==NULL) return NULL;
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
node *dltnode(node *root,int val)
{
    node *ipre=NULL;
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL && root->key==val)
    {
        free(root);
        return NULL;
    }
    if(root->key > val) root->left=dltnode(root->left,val);
    else if(root->key < val) root->right=dltnode(root->right,val);
    else 
    {
        ipre = InOrderPredecessor(root);
        root->key=ipre->key;
        root->left=dltnode(root->left,ipre->key);
    }
    return root;
}
void main()
{
    node *root=NULL,*x;
    int a,val,search,dlt;
    do
    {
        printf("Press [1] to insert in tree\n");
        printf("Press [2] to delete an element in tree\n");
        printf("Press [3] to search an element in tree\n");
        printf("Press [4] to display tree\n");
        printf("Press [0] for exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 0:
                printf("Exit..");
                break;
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                root=insert(root,val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&dlt);
                dltnode(root,dlt);
                printf("Deleted value: %d\n",dlt);
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter element for search: ");
                scanf("%d",&search);
                if(Issearch(root,search)) printf("%d is present is tree\n");
                else printf("%d is not present is tree\n");
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid input, try again...\n");
                break;                
        }
    }while(a!=0);
}