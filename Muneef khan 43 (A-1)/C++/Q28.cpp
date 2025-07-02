/*Demonstrate rethrowing an exception using some real life scenario*/
#include <iostream>
#include <exception>
#include <string>
using namespace std;
void validateacc(const string &acc)
{
    if (acc.empty())
    {
        throw invalid_argument("Invalid acc: acc number is empty.");
    }
}
void transferFunds(const string &acc, double bal, double amt)
{
    try
    {
        validateacc(acc);
        if (bal < amt)
        {
            throw runtime_error("Insufficient bal for the transfer.");
        }
        cout << "Transferring $" << amt << " to acc: " << acc << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error in transferFunds: " << e.what() << endl;
        throw;
    }
}
int main()
{
    try
    {
        string acc;
        double bal, amt;
        cout << "Enter acc no." << endl;
        cin >> acc;
        cout << "Enter bal" << endl;
        cin >> bal;
        cout << "Enter amt." << endl;
        cin >> amt;
        transferFunds(acc, bal, amt);
    }
    catch (const invalid_argument &e)
    {
        cout << "User Notification: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "User Notification: " << e.what() << endl;
    }
    cout << "End of Program" << endl;
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}