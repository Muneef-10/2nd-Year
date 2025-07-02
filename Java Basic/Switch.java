//Press 1 for hello 2 for hii 3 for bonjour
import java.util.*;
public class Switch 
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        System.out.print("Press 1,2 or 3: ");
        int a=sc.nextInt();
        switch(a)
        {
            case 1: System.out.println("Hello");
                    break;
            case 2: System.out.println("Hii");
                    break;
            case 3: System.out.println("Bonjour");
                    break;
            default: System.out.println("Invalid input");
        }
        sc.close();
    }
}
