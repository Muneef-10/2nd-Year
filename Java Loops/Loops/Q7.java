// 1
// 12
// 123
// 1234

package Loops;
import java.util.*;

class NumberHalfPyramid
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int n=sc.nextInt();

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                System.out.print(j);

            System.out.println();
        }
        sc.close();
    }
}
