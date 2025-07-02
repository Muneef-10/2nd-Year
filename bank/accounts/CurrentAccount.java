package bank.accounts;

public class CurrentAccount extends BankAccount
{

    public CurrentAccount(String accountNumber, String accountHolderName, double balance )
    {
        super(accountNumber,accountHolderName,balance);
    }
    public void withdraw(double amount)
    {
        if(amount>balance)
        {
            System.out.println("Insufficient balance");
        }
        else
        {
            balance-=amount;
            System.out.println("Current balance is Rs.:"+balance);
        }
    }
}
