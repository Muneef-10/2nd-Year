#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    string city[5]={"Delhi","Mumbai","Kolkata","Chennai","Dehradun"};
    int data[4][5];
    for (int i = 0; i < 4; i++)
    {
        cout<<"Day "<<i+1<<" temperature in "<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<city[j]<<": ";
            cin>>data[i][j];
        }        
    }
    cout<<setw(15)<<"Days";
    for (int i = 0; i < 5; i++)
    {
        cout<<setw(15)<<city[i];
    }
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<setw(15)<<i+1;
        for (int j = 0; j < 5; j++)
        {
            cout<<setw(15)<<data[i][j];
        }
        cout<<endl;
    }
    int max=data[0][0];
    int min=data[0][0];
    string max1=city[0],min1=city[0];
    int max2=1,min2=1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(data[i][j]>max)
            {
                max=data[i][j];
                max1=city[j];
                max2=i+1;
            }
            if(data[i][j]<min)
            {
                min=data[i][j];
                min1=city[j];
                min2=i+1;
            }
        }  
    }
    cout<<"Min temp on Day '"<<min2<<"' is '"<<min<<"' in city: "<<min1<<endl;
    cout<<"Max temp on Day '"<<max2<<"' is '"<<max<<"' in city: "<<max1<<endl;
    
    return 0;
}