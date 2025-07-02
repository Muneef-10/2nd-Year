//Count the number of element strictly greater than value x.

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    cout<<"Enter size of vector: ";
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<"Enter x: ";
    cin>>x;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int a=0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]>x) a=a+1;
    }
    cout<<"Total number which is greater than "<<x<<" is "<<a;

    return 0;
}