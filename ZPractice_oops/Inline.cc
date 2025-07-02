#include<iostream>
using namespace std;
inline int square(int a)
{
    return a*a;
}
inline int cube(int a)
{
    return a*a*a;
}
int main()
{
    cout<<square(5)<<endl;
    cout<<cube(5)<<endl;
    return 0;
}