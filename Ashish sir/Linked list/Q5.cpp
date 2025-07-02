#include<iostream>
using namespace std;
struct node1
{
    int cons1;
    int exp1;
    struct node1 *next;
};
struct node2
{
    int cons2;
    int exp2;
    struct node2 *next;
};
struct node3
{
    int cons3;
    int exp3;
    struct node3 *next;
};
node1 *push(node1* h1,int a, int b)
{
    node1*tmp1 = (node1*)malloc(sizeof(node1));
    tmp1->cons1=a;
    tmp1->exp1=b;
    tmp1->next=h1;
    h1=tmp1;
    return h1;
}
node2 *push2(node2* h2,int a, int b)
{
    node2*tmp2 = (node2*)malloc(sizeof(node2));
    tmp2->cons2=a;
    tmp2->exp2=b;
    tmp2->next=h2;
    h2=tmp2;
    return h2;
}
node3 *sum(node1* h1, node2* h2)
{
    
}
typedef node1 node1;
typedef node2 node2;
typedef node3 node3;
int main()
{
    node1 *h1=NULL;
    node2 *h2=NULL;
    node2 *h3=NULL;
    h1=push(h1,3,3);
    h1=push(h1,2,2);
    h1=push(h1,1,1);

    h2=push2(h2,2,2);
    h2=push2(h2,3,1);
    h2=push2(h2,1,0);

    sum(h1,h2);

    
    return 0;
}