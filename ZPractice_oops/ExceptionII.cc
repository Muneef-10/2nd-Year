#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    
    try
    {
        if(b==0)
            throw "Divide by Zero is not posssible";
        c=a/b;
        cout<<c<<endl;
    }
    catch(const char *e)
    {
        cout<<"Exception occured: "<<e<<endl;
    }
    
    return 0;
}