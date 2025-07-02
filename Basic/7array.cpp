#include<iostream>
using namespace std;
int main()
{
    // int arr[]={1,2,3};
    // cout<<arr[2]<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    
    int m[5];
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter marks of "<<i+1<<"th student: ";
        cin>>m[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<"Marks of "<<i+1<<"th student is: "<<m[i];
        cout<<"\n";
    }
    
    

    return 0;
}
