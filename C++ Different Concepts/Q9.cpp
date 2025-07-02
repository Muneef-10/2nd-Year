//Q-9)Write a C++ program to find the maximum occurring character in a string.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    cout<<"Enter the string: ";
    getline(cin,st);
    char ch=' ';
    int max=0,frq[256]={0};

    for (int i = 0; i < st.length(); i++)
    {
        frq[st[i]]++;
    }
    
    for (int i = 0; i < st.length(); i++)
    {
        if(frq[st[i]] > max)
        {
            max=frq[st[i]];
            ch=st[i];
        }
    }

    cout<<"Maximum occuring character in the given string is '"<<ch<<"' it comes "<<max<<" times "<<endl<<endl;   
    
    cout<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}