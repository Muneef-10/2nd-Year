// // WAP to calculate a ticket fare with 60+ age 20% off and 12- age 50% off.
// package Class;
// import java.util.*;
// public class Ticket
// {
//     public static void main(String []args)
//     {
//         Scanner sc=new Scanner(System.in);
//         double choice, age,distance,fare=0;
//         String name;
//         System.out.print("Enter name: ");
//         name=sc.nextLine();
//         System.out.print("Enter Age: ");
//         age=sc.nextDouble();
//         System.out.print("Enter distance: ");
//         distance=sc.nextDouble();
//         System.out.println("Press [1] for General class\nPress [2] for Sleeper class\nPress [3] for A.C class");
//         choice=sc.nextDouble();

//         if(choice==1)   fare=2*distance;
//         else if(choice==2)  fare=5*distance;
//         else if(choice==3)  fare=10*distance;
//         else System.out.println("Enter valid input, 1,2 or 3");

//         if(age>60)  fare=0.8*fare;
//         else if(age<12) fare=0.5*fare;

//         System.out.println("Passenger name: "+name+"\nAge: "+age);
//         if(choice==1) System.out.println("Coach: General");
//         else if(choice==2) System.out.println("Coach: Sleeper");
//         else if(choice==3) System.out.println("Coach: A.C");
//         System.out.println("Total price: "+fare);
//         sc.close();
//     }
// } 