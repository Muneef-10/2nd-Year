/*Write a program that reads 10 integer values from the user, stores them in a vector, and then
  • Displays the elements in the vector.
    • Finds and displays the largest and smallest elements in the vector.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> num(10);
    cout<<"Enter 10 integers:\n";
    for (int i = 0; i < 10; i++)
    {
        cin>>num[i];
    }
    cout<<"Elements in vector is: ";
    for (int i = 0; i < num.size(); i++)
    {
        cout<<num[i]<<" ";
    }

    int max=*max_element(num.begin(),num.end());
    int min=*min_element(num.begin(),num.end());
    cout<<"\nLargest element: "<<max<<endl;
    cout<<"Smallest element: "<<min<<endl;
    
    cout << "End of Program" << endl;
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}