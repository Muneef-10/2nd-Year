//Find the difference between the sum of element at even indices to the sum of elements at odd indices.

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,e=0,o=0;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter "<<n<<" elements:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(i%2==0) e=e+v[i];
        else o=o+v[i];
    }
    cout<<"Difference between the sum of the elements at even and odd indices is: "<<(e-o);
    

    return 0;
}