import java.util.*;
class Bank
{
    private static int accountCounter = 1000;
    private String name;
    private String address;
    private int accountNumber;
    private double balance;

    public Bank(String name,String address,double balance)
    {
        this.name=name;
        this.address=address;
        this.balance=balance;
        this.accountNumber=++accountCounter;
    }
    public int getAccountNumber()
    {
        return accountNumber;
    }

    public void displayInfo()
    {
        System.out.println("Account Number: "+accountNumber);
        System.out.println("Name: "+name);
        System.out.println("Address: "+address);
        System.out.println("Balance: "+balance);
    }

    public void deposit(double amount)
    {
        if(amount>0)
        {
            balance+=amount;
            System.out.println("Amount deposited successfully!");
        }
        else
            System.out.println("Invalid deposit amount.");
    }

    public void withdraw(double amount)
    {
        if(amount>0 && amount<= balance)
        {
            balance-=amount;
            System.out.println("Amount withdraw successfully!");
        }
        else
            System.out.println("Invalid withdrawl amount or insufficient balance.");
    }
    public void changeAddress(String newAddress)
    {
        this.address=newAddress;
        System.out.println("Address updated successfully!");
    }
}

class BankApplication
{
    public static void main(String[] args)
    {
        Scanner scanner=new Scanner(System.in);
        ArrayList<Bank> customers=new ArrayList<>();

        System.out.println("Enter the number of depositors: ");
        int numDepositors = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < numDepositors; i++) 
        {
            System.out.println("Enter details for depositor "+ (i+1)+":");
            System.out.println("Name: ");
            String name=scanner.nextLine();
            System.out.println("Address: ");
            String address=scanner.nextLine();
            System.out.println("Initial Balance: ");
            Double balance=scanner.nextDouble();
            scanner.nextLine();
            customers.add(new Bank(name,address,balance));
        }

        boolean exit=false;
        while (!exit) 
        {
            System.out.println("\nBank Operations:");
            System.out.println("1 - Display depositor information");
            System.out.println("2 - Deposit amount");
            System.out.println("3 - Withdraw amount");
            System.out.println("4 - Change address");
            System.out.println("5 - Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter account number: ");
                    int accNum = scanner.nextInt();
                    scanner.nextInt();
                    for (Bank customer : customers)
                    {
                        if(customer.getAccountNumber()==accNum)
                            customer.displayInfo();    
                    }
                    break;
                case 2:
                    System.out.print("Enter account number: ");
                    accNum = scanner.nextInt();
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = scanner.nextDouble();
                    scanner.nextInt();
                    for (Bank customer : customers)
                    {
                        if(customer.getAccountNumber()==accNum)
                        {
                            customer.deposit(depositAmount);
                            customer.displayInfo();
                        }
                    }
                    break;
                case 3:
                    System.out.println("Enter account number: ");
                    accNum=scanner.nextInt();
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = scanner.nextDouble();
                    scanner.nextLine();
                    for (Bank customer : customers) 
                    {
                        if(customer.getAccountNumber()==accNum)
                        {
                            customer.withdraw(withdrawAmount);
                            customer.displayInfo();
                        }    
                    }
                    break;
                case 4:
                    System.out.println("Enter account number: ");
                    accNum=scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("Enter new address: ");
                    String newAddress = scanner.nextLine();
                    for (Bank customer : customers)
                    {
                        if(customer.getAccountNumber()==accNum)
                        {
                            customer.changeAddress(newAddress); 
                            customer.displayInfo();
                        }    
                    }
                    break;
                case 5:
                    System.out.println("Exiting application.");
                    scanner.close();
                    exit=true;
                    break;

                default:
                    System.out.println("Invalid choice , Please try again. ");
                    break;
            }
        }

    }
}