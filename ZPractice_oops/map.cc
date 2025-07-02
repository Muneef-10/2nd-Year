#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,int>m;
    m[1]=8;
    m[2]=9;
    m[3]=10;
    for (auto it =m.begin(); it!=m.end(); it++)
    {
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    
    return 0;
}