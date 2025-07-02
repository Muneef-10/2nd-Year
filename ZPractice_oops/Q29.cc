/*Write a program to copy the contents of one text file to another while changing the case of every alphabet*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("zoom.txt");
    ofstream fout("z2.txt");
    if(!fin.is_open() || !fout.is_open())
    {
        cerr<<"Error occurred in opening"<<endl;
        return 0;
    }
    char ch;
    ch=fin.get();
    while (!fin.eof())
    {
        if(isalpha(ch))
        {
            if(islower(ch)) ch= toupper(ch);
            else ch=tolower(ch);
        }
        fout<<ch;
        ch=fin.get();
    }
    
    return 0;
}