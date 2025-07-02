//Add two numbers
import java.util.*;
class Algebra
{
    int a;
    int b;
    Algebra(int x,int y)
    {
        System.out.println("Constructor is called");
        a=x;
        b=y;
    }
    int add()
    {
        return a+b;
    }
    int sub()
    {
        return a-b;
    }
    int mul()
    {
        return a*b;
    }
}
public class Q1
{
    public static void main(String[] args) 
    {
        Algebra obj= new Algebra(5,7);

        Scanner sc=new Scanner(System.in) ;

        // System.out.println("Enter two number to sum");
        // int b=sc.nextInt();
        // int a=sc.nextInt();
        int ans=obj.add();
        // System.out.println("Sum of "+a+" and "+b+" is: "+ans);
        System.out.println("Sum is: "+ans);
        System.out.println("Sub is: "+obj.sub());
        System.out.println("Mul is: "+obj.mul());
        sc.close();
    }
}