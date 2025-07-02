#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*add;
};
typedef struct node node;

node*start=NULL,*temp,*newnode;

void create(){
    int n;
    char ch;
    printf("enter element");
    scanf("%d",&n);
    start=(node*)malloc(sizeof(node));
    start->data=n;
    start->add=NULL;
    temp=start;
    printf("want to continue(y for yes,n for no)");
    ch=getchar();
    ch=getchar();
while(ch=='y'){
    printf("enter next element");
    scanf("%d",&n);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->add=NULL;
    temp->add=newnode;
    temp=temp->add;
     printf("want to continue(y for yes,n for no)");
    ch=getchar();
    ch=getchar();
}
}
void display(){
    if(start==NULL){
        printf("list not found");
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->add;
        }
    }
}
int main(){
    create();
    display();
    return 0;
}