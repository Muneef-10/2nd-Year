package bank.accounts;

public class SavingsAccount extends BankAccount
{
    final int limit=100000;
    public SavingsAccount(String accountNumber, String accountHolderName, double balance)
    {
        super(accountNumber,accountHolderName,balance);
    }
    public void withdraw(double amount)
    {
        if(amount>limit)
        {
            System.out.println("Unable to withdraw, you reached the daily limit");
        }
        else if(amount>balance)
            System.out.println("Insufficient balance");
        else
        {
            balance-=amount;
            System.out.println("Current balance is Rs.:"+balance);
        }
    }
}