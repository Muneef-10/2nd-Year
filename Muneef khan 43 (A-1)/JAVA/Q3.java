//Program to find if the given numbers are Friendly pair or not (Amicable or not). Friendly Pair are two or more numbers with a common abundance.
import java.util.Scanner;
class Amicable
{
    static int sumOfDivisors(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n / 2; i++) 
        {
            if (n % i == 0)
                sum += i;
        }
        return sum;
    }

    static boolean isFriendlyPair(int n1, int n2) {
        int sum1 = sumOfDivisors(n1);
        int sum2 = sumOfDivisors(n2);
        // System.out.println("Sum of divisors 1"+n1+": "+sum1);
        // System.out.println("Sum of divisors 2"+n2+": "+sum2);  this is not printing here
        return ((sum1 == n1) && (sum2 == n2));
        // return (sum1 * n2 == sum2 * n1);
    }

    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter two numbers: "); 
        int n1 = sc.nextInt(); 
        int n2 = sc.nextInt(); 
        if (isFriendlyPair(n1, n2))
            System.out.println("Friendly Pair."); 
        else 
            System.out.println("Not Friendly Pair."); 
        
        System.out.println("*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
        sc.close();
    }
}






/*import java.util.*;
public class zz 
{
    static int SOD(int a)
    {
        int sum=0;
        for(int i=1;i<=a/2;i++)
        {
            if(a%i==0)
                sum+=i;
        }
        return sum;
    }
    static boolean isFriendlyPair(int x,int y)
    {
        int sum1=SOD(x);
        int sum2=SOD(y);
        System.out.println("SOD of "+x+" is: "+sum1);
        System.out.println("SOD of "+y+" is: "+sum2);
        return (sum1==x && sum2 ==y);
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 2 number: ");
        int x=sc.nextInt();
        int y=sc.nextInt();
        if(isFriendlyPair(x,y))
            System.out.println("Yes");
        else 
            System.out.println("No");

        sc.close();
    }
}
 */