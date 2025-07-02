package Loops;
import java.util.*;

class Rectangle 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int n=sc.nextInt();
        System.out.print("Enter number of columns: ");
        int m=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        sc.close();
    }
}
