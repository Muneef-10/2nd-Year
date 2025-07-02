package Loops;
import java.util.*;
class Sample
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter string: ");
        String example=sc.nextLine();
        // for(int i=0;i<100;i++)
        // {
        //     System.out.println(i+1+". "+example);
        // }

        int i=0;
        // while(i<10)
        // {
        //     System.out.println(i+1+". "+example);
        //     i++;
        // }

        do
        {
            System.out.println(i+1+". "+example);
            i++;
        }while(i<10);
        sc.close();
    }

}
