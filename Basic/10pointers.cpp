#include<iostream>
using namespace std;
int main()
{
    int a=34;
    int* ptra;
    ptra=&a;
    cout<<"Value of a is: "<<*ptra<<endl;
    cout<<"Value of a is: "<<a<<endl;
    cout<<"Address of a is"<<&a<<endl;
    cout<<"Address of a is"<<ptra;
    return 0;
}