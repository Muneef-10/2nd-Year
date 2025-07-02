// Create a program to count the word in a string.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string sentence="the quick brown fox jumps over the lazy dog";
    map<string,int>wordCount;
    string word="";
    for(char ch:sentence)
    {
        if(isalnum(ch))
            word+=ch;
        else if(!word.empty())
        {
            wordCount[word]++;
            word="";
        }
    }
    if(!word.empty())
        wordCount[word]++;
    cout<<"Word Frequencies:"<<endl;
    for(auto it=wordCount.begin();it!=wordCount.end();++it)
        cout<<it->first<<":"<<it->second<<endl;
    cout << endl;
    cout << "*************************************************************************************" << endl;
    cout<< "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout<< "*************************************************************************************" << endl;
    return 0;
}