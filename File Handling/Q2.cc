#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("zoom.txt");
    char ch;
    // fin>>ch;
    ch=fin.get();
    while(!fin.eof())
    {
        cout<<ch;
        // fin>>ch;
        ch=fin.get(); 
    }
    fin.close();

    return 0;
}