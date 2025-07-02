/*Write a program to count number of characters, words and lines in a file.*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;
    while (getline(inputFile, line))
    {
        lineCount++;
        charCount += line.length()+1;
        stringstream ss(line);
        string word;
        while (ss >> word)
            wordCount++;
    }
    cout << "no. of characters: " << charCount  << endl;
    cout << "no. of words: " << wordCount << endl;
    cout << "no. of lines: " << lineCount << endl;
    inputFile.close();
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl; return 0;
}
