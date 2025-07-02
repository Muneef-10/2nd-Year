//Write a program to copy the contents of one text file to another while changing the case of every alphabet
// #include<cctype>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inputFile("source.txt");
    ofstream outputFile("destination.txt");

    if(!inputFile.is_open() || !outputFile.is_open()){
        cout<<"Eror opening file!"<<endl;
        return 1;
    }
    char ch;
    while(inputFile.get(ch))
    {
        if(isalpha(ch))
        {
            //change the case : lowercase to uppercase, uppercase to lowercase
            ch=islower(ch) ? toupper(ch): tolower(ch);
        }
        outputFile.put(ch);
    }
    cout<<"File copied with case conversion."<<endl;
    inputFile.close();
    outputFile.close();
    return 0;
}