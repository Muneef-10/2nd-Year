// Construct a C++ program that removes a specific character from a given string and return the updated string.
#include<iostream>
using namespace std;
int main()
{
    string st;
    char ch;
    cout<<"Enter string: ";
    getline(cin,st);
    cout<<"Enter character: ";
    cin>>ch;
    int j=0;
    cout<<"Normal string: ";    
    cout<<st<<endl; 
    for (int i = 0; i < st.length(); i++)
    {
        if(st[i]!=ch) 
        {
            st[j]=st[i];
            j++;
        }
    }
    st.resize(j);
    cout<<"After deletion "<<ch<<" string: ";
    cout<<st<<endl; 

    return 0;
}