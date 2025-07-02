package bank.loans;

public class PersonalLoan implements LoanService
{
    protected double amount,interestRate;
    protected int tenure;
    public void applyLoan(double amount, double interestRate, int tenure)
    {
       this.amount=amount;
       this.interestRate=interestRate;
       this.tenure=tenure;
       System.out.println("Personal loan applied successfully"); 
    }
    public double calculateEMI()
    {
        double monthlyRate = interestRate / 12 / 100; 
        double emi = (amount * monthlyRate * Math.pow(1 + monthlyRate, tenure)) / (Math.pow(1 + monthlyRate, tenure) - 1); 
        return emi; 
    }
}
