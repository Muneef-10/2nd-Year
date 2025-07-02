//1
//0 1
//1 0 1
//0 1 0 1
//1 0 1 0 1

package Loops;
import java.util.*;

class BinaryTriangle
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int n=sc.nextInt();//a
        for(int i=1;i<=n;i++)
        {
            // if(i%2!=0) a=1;
            // else a=0;
            // for(int j=1;j<=i;j++)
            // {
            //     System.out.print(a+" ");
            //     if(a==0) a=1;
            //     else a=0;        
            // }

            for (int j = 1; j <=i; j++) 
            {
                int sum=i+j;
                if(sum%2==0)  System.out.print("1 ");
                else  System.out.print("0 ");
            }
            System.out.println();
        }
        sc.close();
    }

}