package Loops;
import java.util.*;

public class PrintSum 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number for sum: ");
        int a=0,n=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            a=a+i;
        }
       System.out.print("Sum is: "+a); 
       sc.close();
    }
}
