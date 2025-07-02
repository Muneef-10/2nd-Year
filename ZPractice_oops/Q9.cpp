//Write a C++ program to find the maximum occurring character in a string.
#include<iostream>
using namespace std;
int main()
{
    string str;
    int max=0;
    char ch;
    cout<<"Enter string: ";
    getline(cin,str);
    int frq[256]={0};
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]!=' ')
        frq[str[i]]=frq[str[i]]+1;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if(frq[str[i]]>max )
        {
            max=frq[str[i]];
            ch=str[i];
        }
    }
    cout<<ch<<" has maximum occurence in given string and that is: "<<max;
    
    return 0;
}