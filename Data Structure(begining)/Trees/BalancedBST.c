#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int key;
    struct Node *left,*right;
}node;
node *create(int val)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->right=NULL;
    tmp->left=NULL;
    tmp->key=val;
    return tmp;
}
node *insert(node *root,int val)
{
    if(root==NULL) return create(val);
    if(root->key==val) return root;
    if(root->key>val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
}
void Inorder(node *root,int *sortval,int *i)
{
    if(root==NULL) return;
    Inorder(root->left,sortval,i);
    sortval[(*i)++]=root->key;
    Inorder(root->right,sortval,i);
}
void print(node *root)
{
    if(root==NULL) return;
    node *queue[50],*tmp;
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        tmp=queue[front++];
        printf("%d ",tmp->key);
        if(tmp->left!=NULL) queue[rear++]=tmp->left;
        if(tmp->right!=NULL) queue[rear++]=tmp->right;
    }
}
node *balancebst(int val[],int start,int end)
{
    if(start>end) return NULL;
        int mid=start+(end-start)/2;
        node *curr=(node *)malloc(sizeof(node));
        curr->key=val[mid];
        curr->left=balancebst(val,start,mid-1);
        curr->right=balancebst(val,mid+1,end);
        return curr;
}
void main()
{
    int n;
    node *root=NULL;
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter element: ");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    int i=0,sortval[n];
    Inorder(root,sortval,&i);
    printf("Noraml tree: ");
    print(root);
    printf("\nBalanced tree: ");
    node *newroot=balancebst(sortval,0,n-1);
    print(newroot);
    
}