import java.util.*;
import java.io.*;

class Sample
{
    public static void main(String[] args)
    {
        PrintStream ps=System.out;
        Scanner sc=new Scanner(System.in);

        ps.println("Enter name 1: ");
        String name=sc.nextLine(); //input for one word if we write 'sc.next()'
        // sc.nextLine();
        // System.out.println("Enter name 2: ");
        ps.println("Enter name 2: ");
        String name2=sc.nextLine(); //input for Line
        System.out.println(name);
        System.out.println(name2);
        int b,a=10;
        b=a;
        System.out.println(b);
        sc.close();
    }
}