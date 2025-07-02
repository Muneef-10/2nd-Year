//Take 2 variables 'a' and 'b' and print their sum.
import java.util.*;

public class Sum
{
    public static void main(String []args)
    {
        float a,b; // Use double also
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter 1st number: ");
        a=sc.nextFloat();
        System.out.print("Enter 2nd number: ");
        b=sc.nextFloat();
        System.out.println("Sum is "+(a+b));
        
        //Constanat value
        final int x=10;
        System.out.println(x);   
        sc.close();
    }
}