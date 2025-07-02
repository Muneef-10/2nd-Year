#include<iostream>
using namespace std;
void reverse(string &str,int start,int end)
{
    while(start<end)
    {
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
int main()
{
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int start=0;
    for (int i = 0; i <=str.length(); i++)
    {
        if(str[i]==' ' || i==str.length())
        {
            reverse(str,start,i-1);
            start=i+1;
        }
    }
    cout<<str;
    return 0;
}