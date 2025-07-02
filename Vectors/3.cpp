//Find the last occurrence of an elements x in a given array.(using vector).

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter "<<n<<" Elements:"<<endl;
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
    
    // for (int i = n-1; i >=0; i--)
    // {
    //     if(v[i]==x)
    //     {
    //         cout<<i;
    //         break;
    //     }
    // }
    //2nd method below:
    int z;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==x) z=i;
    }
    cout<<z;

    return 0;
}