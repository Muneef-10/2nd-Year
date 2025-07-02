/* *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      **/

package Loops;
import java.util.*;

class ButterFly
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int n=sc.nextInt();
        for (int i = 1; i <=n; i++) 
        {
            for (int j = 1; j <=i; j++) 
                System.out.print("*");

            int space = 2*(n-i);
            for(int j=1;j<=space;j++)
                System.out.print(" ");

            for(int j=1;j<=i;j++)
                System.out.print("*");

            System.out.println();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=i;j--)
                System.out.print('*');

            int space=2*(i-1);
            for(int j=1;j<=space;j++)
                System.out.print(" ");

            for(int j=n;j>=i;j--)
                System.out.print('*');

            System.out.println();
        }
        sc.close();
    }
}