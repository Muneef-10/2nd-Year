/*Create a program to store and display a list of integers (up to 20 values) entered by the user.
The program should:
• Display the list in the order entered.
• Remove the first and last element from the list.
• Display the updated list.*/

#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>numbers;
    int num;
    cout<<"Enter up to 10 integers(enter a negative number to stop): ";
    while(numbers.size()<10)
    {
        cin>>num;
        if(num<0) break;
        numbers.push_back(num);
    }
    cout<<"Normal List: ";
    for(int n:numbers)
    {
        cout<<n<<" ";
    }
    if(!numbers.empty())
    {
        numbers.pop_front();
        numbers.pop_back();
    }

    cout<<"\nList after removing first and last element: ";
    for(int n:numbers)
    {
        cout<<n<<" ";
    }
    cout<<endl;
    cout << "\n*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    
    return 0;
}