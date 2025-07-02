/*Write a java program to create a class named 'Bank ' with the following data members: 
 Name of depositor 
 Address of depositor 
 Account Number 
 Balance in account 
 
Class 'Bank' has a method for each of the following:  
1 - Generate a unique account number for each depositor For first depositor, account number will be 1001, for 
second depositor it will be 1002 and so on 
2 - Display information and balance of depositor 
3 - Deposit more amount in balance of any depositor 
4 - Withdraw some amount from balance deposited 
5 - Change address of depositor  */
import java.util.Scanner; 
 
class Bank 
{ 
 
    private String name, address; 
    private int accountNumber; 
    private double balance; 
    private static int accountCounter = 1001; 
 
    public Bank(String name, String address, double balance) { 
        this.name = name; 
        this.address = address; 
        this.accountNumber = accountCounter++; 
        this.balance = balance; 
    } 
 
    public int getAccountNumber() { 
        return accountNumber; 
    }  
    public void setAddress(String newAddress) { 
        this.address = newAddress; 
    } 
 
    public void deposit(double amount) { 
        if (amount > 0) { 
            this.balance += amount; 
        } 
    } 
 
    public void withdraw(double amount) { 
        if (amount > 0 && amount <= balance) { 
            this.balance -= amount; 
        } 
    } 
 
    public void displayInfo() { 
        System.out.println("Account Number: " + accountNumber); 
        System.out.println("Name: " + name); 
        System.out.println("Address: " + address); 
        System.out.println("Balance: $" + balance); 
    } 
 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter number of depositors: "); 
        int n = sc.nextInt(); 
        sc.nextLine(); 
 
        Bank[] accounts = new Bank[n]; 
        for (int i = 0; i < n; i++) { 
            System.out.println("\nEnter details for depositor " + (i + 1) + ":"); 
            System.out.print("Name: "); 
            String name = sc.nextLine(); 
            System.out.print("Address: "); 
            String address = sc.nextLine(); 
            System.out.print("Initial Balance: "); 
            double balance = sc.nextDouble(); 
            sc.nextLine(); 
            accounts[i] = new Bank(name, address, balance); 
            System.out.println("Account created! Account Number: " + accounts[i].getAccountNumber()); 
        } 
        while (true) 
        { 
            System.out.println("\n1. Display details\n2. Deposit\n3. Withdraw\n4. Change address\n5. Exit"); 
            System.out.print("Choose an option: "); 
            int choice = sc.nextInt(); 
            if (choice == 5) { 
                break; 
            } 
            System.out.print("Enter account number: "); 
            int accNum = sc.nextInt(); 
            sc.nextLine(); 
            Bank account = null; 
 
            for (Bank acc : accounts) { 
                if (acc.getAccountNumber() == accNum) { 
                    account = acc; 
                    break; 
                } 
            } 
            if (account == null) { 
                System.out.println("Account not found!"); 
                continue; 
            } 
            if (choice == 1) { 
                account.displayInfo(); 
            } else if (choice == 2) { 
                System.out.print("Enter deposit amount: "); 
                account.deposit(sc.nextDouble()); 
                account.displayInfo(); 
            } else if (choice == 3) { 
                System.out.print("Enter withdrawal amount: "); 
                account.withdraw(sc.nextDouble()); 
                account.displayInfo(); 
            } else if (choice == 4) { 
                System.out.print("Enter new address: "); 
                account.setAddress(sc.nextLine()); 
                account.displayInfo(); 
            } else { 
                System.out.println("Invalid option."); 
            } 
        } 
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        sc.close(); 
    } 
}