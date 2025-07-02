#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    string car[4]={"Marti-K10","Zen-Astelo","Wagnor","Maruti-SX4"};
    string city[4]={"Delhi","Mumbai","Chennai","Kolkata"};
    int data[4][4]={0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<"Enter number of "<<car[j]<<" owned in "<<city[i]<<": ";
            cin>>data[i][j];
        }
    }
    cout<<setw(15)<<"Cities";
    for (int i = 0; i < 4; i++)
    {
        cout<<setw(15)<<car[i];
    }
    cout<<endl; 
    for (int i = 0; i < 4; i++)
    {
        cout<<setw(15)<<city[i];
        for (int j = 0; j < 4; j++)
        {
            cout<<setw(15)<<data[i][j];
        }
        cout<<endl;
    }
    
    
    return 0;
}