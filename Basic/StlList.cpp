#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(10);
    l.emplace_back(20);
    l.push_front(12);  // it is very cheap in time complexity as compared to insert
    l.emplace_front(40);

    for (auto it=l.begin(); it !=l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<"\n";
    l.pop_front();
    for (auto it=l.begin(); it !=l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //Approx all the functions are same as VECTOR.
    l.sort();
    for (auto it=l.begin(); it !=l.end(); it++)
    {
        cout<<*it<<" ";
    }

    return 0;
}