package bank.main;

import bank.accounts.*;
import bank.loans.*;

public class BankApplication
{
    public static void main(String []args)
    {
        SavingsAccount sa=new SavingsAccount("M101", "Ayan", 50000);
        sa.deposit(5000);
        sa.withdraw(30000);
        sa.withdraw(20000);
        sa.displayBalance();

        System.out.println();

        CurrentAccount ca=new CurrentAccount("S201", "Zubair", 100000);
        ca.withdraw(4000);
        ca.deposit(1000);
        ca.displayBalance();

        System.out.println();

        LoanService hl=new HomeLoan();
        hl.applyLoan(1000000, 8.5, 240);
        System.out.println("Home Loan EMI: Rs. "+hl.calculateEMI());
        System.out.println();

        LoanService pl = new PersonalLoan(); 
        pl.applyLoan(500000, 12.0, 60); 
        System.out.println("Personal Loan EMI: Rs."+pl.calculateEMI());

        System.out.println("*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
    }
}