// 1234
// 123
// 12
// 1

package Loops;
import java.util.*;
class  InvertedNumberHalfPyramid
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        System.out.print("Enter number of rows: ");
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n-i;j++)
                System.out.print(j);
            System.out.println();
        }
        sc.close();
    }
}