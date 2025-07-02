// Print table of a number.
import java.util.*;

public class Table
{
    public static void main(String[] args)
    {
        int a;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number for table: ");
        a=sc.nextInt();
        for(int i=1;i<=10;i++)
        {
            System.out.println(a+"x"+i+"="+(a*i));
        }
        sc.close();
    }
}