#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
}node;
node *create(int val)
{
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=val;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}
node* insert(node *root,int val)
{
    if(root==NULL) return create(val);
    if(root->data==val) return root;
    if(root->data > val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
}
int height(node *root)
{
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    if(left>right) return left +1;
    else return right +1;
}
node *search(node *root,int val)
{
    if(root==NULL||root->data==val ) return root;
    if(root->data > val) return search(root->left,val);
    else return search(root->right,val);
    // return NULL;
}
int depth(node *root, int val)
{
    return height(search(root,val))-1;
}
void inorder(node *root)
{
    if(root==NULL) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
node *getsucc(node *root)
{
    root=root->right;
    while(root->left!=NULL) root=root->left;
    return root;
}
node *delete(node *root,int val)
{
    if(root==NULL) return root;
    if(root->data > val) root->left=delete(root->left,val);
    else if(root->data < val) root->right=delete(root->right,val);
    else
    {
        if(root->left==NULL)
        {
            node*tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL)
        {
            node*tmp=root->left;
            free(root);
            return tmp;
        }

            node *succ=getsucc(root);
            root->data=succ->data;
            root->right=delete(root->right,succ->data);
    }
    return root;
}
void main()
{
    int choice;
    node *root=NULL;
    printf("Press [1] to create node\n");
    printf("Press [2] to insert node\n");
    printf("Press [3] to delete node\n");
    printf("Press [4] to find height of tree\n");
    printf("Press [5] to find depth of tree\n");
    printf("Press [6] to search element\n");
    printf("Press [7] to display in inorder\n");
    printf("Press [0] to exit\n");
    while(choice!=0)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            printf("Exit..\n");
            break;
        case 1:
        {
            int val;
            printf("Enter element: ");
            scanf("%d",&val);
            root=create(val);
            break;
        }
        case 2:
        {
            int val;
            printf("Enter element: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        }
        case 3:
        {
            int val;
            printf("Enter value to be deleted: ");
            scanf("%d",&val);
            printf("Value is deleted: %d",val);
            root=delete(root,val);
            break;
        }
        case 4:
            inorder(root);
            printf("Height of tree is: %d",height(root));
            break;  
        // case 5:
        // {
        //     int val;
        //     printf("Enter element from where you find the depth: ");
        //     scanf("%d",&val);
        //     printf("Depth of node elemnt %d is: %d",val,depth(root,val));  //Depth of root node is same as height but depth of node is height -1 
        //     break; 
        // } 
        case 6:
        {
            int val;
            printf("Enter element to search: ");
            scanf("%d",&val);
            node *tmp=search(root,val);
            if(tmp!=NULL)
                printf("Value found\n");
            else printf("Value not found\n");
            break; 
        } 
        case 7:
            inorder(root);
            break;
        default:
            printf("Invalid input,try again..");
            break;
        }
    }
}