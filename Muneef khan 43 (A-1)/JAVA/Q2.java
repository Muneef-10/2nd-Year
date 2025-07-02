import java.util.*; 
class Q2 
{ 
    public static void main(String args[]) 
    { 
        Scanner sc= new Scanner(System.in); 
 
        System.out.println("Press 1. for Term Deposit\nPress 2. for Recurring Deposit"); 
        int choice=sc.nextInt(); 
        switch (choice) { 
            case 1: 
                { 
                    double p,r,t; 
                    System.out.print("Enter principal: "); 
                    p=sc.nextInt(); 
                    System.out.print("Enter rate of interest: "); 
                    r=sc.nextInt(); 
                    System.out.print("Enter time period in years: "); 
                    t=sc.nextInt(); 
                    double a=p*Math.pow((1+r/100),t); 
                    System.out.println("Receivable amount: "+a); 
                    break; 
                } 
            case 2: 
                { 
                    double p,r,t; 
                    System.out.print("Enter monthly installment: "); 
                    p=sc.nextInt(); 
                    System.out.print("Enter rate of interest: "); 
                    r=sc.nextInt(); 
                    System.out.print("Enter time period in months: "); 
                    t=sc.nextInt(); 
                    double a=p*t+p * t*(t+1)/2 * r/100 * 1/12; 
                    System.out.println("Receivable amount: "+a); 
                    break; 
                } 
            default: 
                System.out.println("Invalid input press 1 or 2"); 
                break; 
        } 
         
        System.out.println("*************************************************************"); 
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43"); 
        System.out.println("*************************************************************"); 
        sc.close(); 
    } 
}