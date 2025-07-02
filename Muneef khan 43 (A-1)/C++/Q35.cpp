/*Create a program that stores a list of integers entered by the user and then:
• Displays the unique elements (i.e., elements that appear only once) in the list.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> nums;
    int num;
    cout << "Enter integers(enter a negative number to stop):\n";
    while (true)
    {
        cin >> num;
        if (num < 0)
            break;
        nums.push_back(num);
    }
    nums.sort();
    nums.unique();
    cout << "Unique elements in the list: ";
    for (int n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << "*************************************************************************************" << endl;
    cout<< "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout<< "*************************************************************************************" << endl;
    return 0;
}
