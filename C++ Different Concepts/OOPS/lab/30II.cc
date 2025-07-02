//Write a program to count number of characters, words and lines in a file.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inputFile("source.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening file!"<<endl;
        return 1;
    }
    int charCount=0,wordCount=0,lineCount=0;
    string line;
    while(getline(inputFile,line)){
        lineCount++;//Increment line
        charCount+=line.length();
        bool inWord=false;
        for(char ch:line){
            if(isspace(ch)){
                if(inWord){
                    wordCount++;
                    inWord=false;
                }
            }else{
                inWord=true;
            }
        }
        if(inWord)wordCount++; 
    }
    cout<<"Number of character: "<<charCount<<endl;
    cout<<"Number of words: "<<wordCount<<endl;
    cout<<"Number of lines: "<<lineCount<<endl;
}