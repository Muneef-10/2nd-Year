// #include<iostream>
// using namespace std;
// int main()
// {
//     int a[2][3]={
//         {1,2,3},
//         {4,5,6}
//     };
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout<<"Value at ("<<i<<","<<j<<") is "<<a[i][j]<<endl;
//         }
//     }
// }


#include<iostream>
using namespace std;
int main()
{
    int a[2][3];
    cout<<"Enter the value:"<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"Values at index ("<<i<<","<<j<<") is : "<<a[i][j]<<endl;
        }
        
    }
    return 0;
}