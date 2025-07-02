package bank.accounts;

public abstract class BankAccount
{
    protected String accountNumber;
    protected String accountHolderName;
    protected double balance;

    public BankAccount(String accountHolderName,String  accountNumber,double balance)
    {
        this.accountHolderName=accountHolderName;
        this.accountNumber=accountNumber;
        this.balance=balance;
    }
    public void deposit(double amount)
    {
        balance+=amount;
        System.out.println("Deposited Rs."+amount);
    }
    public abstract void withdraw(double amount);
    public void displayBalance()
    {
        System.out.println("Your current balance is Rs."+balance);
    }
}