//Q-7) Construct a C++ program that removes a specific character from a given string and return the updated string.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cout<<"Enter a string: ";
    getline(cin,input);
    int n=input.length();
    char ch;
    cout<<"Enter a character for removing from the string: ";
    cin>>ch;
    int i=0,j=0;
    for (int i = 0; i<n; i++)
    {
        if(input[i]!=ch)
        {
            input[j] = input[i];
            j++;
        }
    }
    input.resize(j);
    cout<<input;
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}