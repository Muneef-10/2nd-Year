// read in file
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    //FIle open krna
    ifstream fin;
    fin.open("zoom.txt");
    char ch;
    // fin>>ch;
    ch=fin.get();
    while (!fin.eof())
    {
        cout<<ch;
        ch=fin.get();
    }
    
    fin.close();
    return 0;
}