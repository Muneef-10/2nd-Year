#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;

    cout<<"Enter 5 elements:"<<endl;
    
    //for loop
    for(int i=0; i<5; i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.insert(v.begin(),20);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.erase(v.end()-2);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for (int i = v.size()-1; i >=0; i--)
    {
        cout<<v[i]<<" ";
    }
    v.clear();
    cout<<"\nV:\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    

    return 0;
}