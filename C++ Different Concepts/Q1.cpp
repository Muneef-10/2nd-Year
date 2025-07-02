//Q-1) Write a program in C++ to display the multiplication table vertically from 1 to n. 

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Input the number upto: ";
    cin>>n;
    cout<<"Table from 1 to "<<n<<" is:\n";
    for (int i = 1; i <=10; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            cout<<j<<"x"<<i<<"="<<(j*i)<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;

    return 0;
}
