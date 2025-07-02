/*Write a program to copy the contents of one text file to another while changing the case of every alphabet.*/
#include <iostream>
#include <fstream> 
#include <cctype>
using namespace std;
int main()
{
    ifstream inputFile("source.txt");
    ofstream outputFile("destination.txt");
    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error Opening" << endl;
        return 1;
    }
    char ch;
    while (inputFile.get(ch))
    {
        if (isalpha(ch))
        {
            ch = islower(ch) ? toupper(ch) : tolower(ch);
        }
        outputFile.put(ch);
    }
    cout << "File copied with case toggled." << endl;
    inputFile.close();
    outputFile.close();
    cout << endl;
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}
