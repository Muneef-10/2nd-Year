// #include<bits/stdc++.h> write in file
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    //FIle open krna
    ofstream fout;
    fout.open("zoom.txt"); //if file not present it create a file and open it
    fout<<"Hello India";

    fout.close();
    return 0;
}