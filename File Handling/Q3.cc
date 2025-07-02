#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;//read
    ofstream fout;//write
    char ch;
    fin.open("zoom.txt");
    fout.open("z2.txt");
    ch=fin.get();
    while(!fin.eof())
    {
        fout<<ch;
        ch=fin.get();
    }
    fin.close();
    fout.close();
}