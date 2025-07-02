package bank.loans;

public interface LoanService 
{
    void applyLoan(double amount, double interestRate, int tenure);
    double calculateEMI();
     
}