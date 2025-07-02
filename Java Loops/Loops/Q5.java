// ****
// ***
// **
// *

package Loops;
import java.util.*;

class InvertedHalfPyramid 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.print("Enter number of rows: ");
        n=sc.nextInt();
        for(int i=n;i>0;i--)
        {
            for(int j=i;j>0;j--)
                System.out.print("*");

            System.out.println();
        }
        sc.close();
    }    
}
