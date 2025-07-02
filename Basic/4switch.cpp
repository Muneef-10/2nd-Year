#include<iostream>
using namespace std;
int main()
{
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    switch(age)
    {
    case 14:
        cout<<"you are 14 yrs old";
        break;
    case 15:
        cout<<"you are 15 yrs old";
        break;
    case 16:
        cout<<"you are 16 yrs old";
        break;
    case 17:
        cout<<"you are 17 yrs old";
        break;
    default:
        cout<<"You are under 14 or over 17 yr of age";
    }

    return 0;
}