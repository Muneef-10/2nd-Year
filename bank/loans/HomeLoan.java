package bank.loans;

public class HomeLoan implements LoanService 
{
    protected double amount,interestRate;
    protected int tenure;
    public void applyLoan(double amount, double interestRate, int tenure)
    {
        this.amount=amount;
        this.interestRate=interestRate;
        this.tenure=tenure;
        System.out.println("Home loan applied successfully");
    }
    public double calculateEMI()
    {
        double monthlyrate=interestRate/12/100;
        double emi=(amount*monthlyrate*Math.pow(1+monthlyrate,tenure))/(Math.pow(1+monthlyrate,tenure)-1);
        return emi;
    }
}
