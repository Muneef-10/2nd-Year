//Q-8) Write C++ program to reverse each word of string.   e.g. Input- I love my India Output – I evol ym aidnI

#include<bits/stdc++.h>
using namespace std;
void reverse(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]!=' ')
        st.push(str[i]);
        else 
        {
            while(st.empty()!=true)
            {
                cout<<st.top();
                st.pop();
            }
            cout<<" ";
        }
    }
    while(st.empty()!=true)
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    reverse(str);  
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}
