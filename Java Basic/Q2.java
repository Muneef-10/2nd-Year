import java.util.*;

public class Q2
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter name 1: ");
        String name=sc.next(); //input for one word

        sc.nextLine();

        System.out.println("Enter name 2: ");
        String name2=sc.nextLine(); //input for Line
        //nextInt()  for int
        //nextFloat()  for float
        

        System.out.println(name);
        System.out.println(name2);
        sc.close();
    } 
}