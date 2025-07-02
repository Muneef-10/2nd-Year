package Loops;
import java.util.*;

public class Prime 
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a number to check it is prime or not: ");
        int x=0,a=sc.nextInt();
        for(int i=2;i<a;i++)
        {
            if(a%i==0)
            {
                x=1;
                System.out.println("Number is not Prime");
                break;
            }
        }
        if(a==1)
        System.out.println("Number is not Prime");
        if(x==0&&a!=1)
        System.out.println("Number is Prime");
        sc.close();
    }
}