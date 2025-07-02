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
    input.erase(remove(input.begin(),input.end(),ch),input.end());
    cout<<input<<endl;

    cout<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}