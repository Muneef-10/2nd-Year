#include<iostream>
#include<exception>
#include<string>
using namespace std;
void ValidateAccount(const string& account)
{
    if(account.empty()){
        throw invalid_argument("Invlid account: Account number is empty.");
    }
}
void transferFunds(const string& account, double balance, double amount){
    try{
        ValidateAccount(account);
        if(balance < amount ){
            throw runtime_error("Insufficient balance for the transfer.");
        }
        cout<<"Transferring $"<<amount<<" to account:"<<account<<endl;
    }
    catch(const exception& e){
        cerr<<"Error in transferFunds: "<<e.what()<<endl;
        throw;
    }
}
int main()
{
    try{
        string account;
        double balance,amount;
        cout<<"Enter account: ";
        cin>>account;
        cout<<"Enter balance: ";
        cin>>balance;
        cout<<"Enter amount: ";
        cin>>amount;

        transferFunds(account,balance,amount);
    }
    catch(const invalid_argument& e){
        cout<<"User Notification: "<<e.what()<<endl;
    }
    catch(const runtime_error& e)
    {
        cout<<"User Notification: "<<e.what()<<endl;
    }
    cout<<"End of program"<<endl;
    return 0;
}
