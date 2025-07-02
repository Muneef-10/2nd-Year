// *
// **
// ***
// ****

package Loops;
import java.util.*;

class HalfPyramid 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.print("Enter number of rows: ");
        n=sc.nextInt();
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                System.out.print("*");

            System.out.println();
        }
        sc.close();
    }    
}
