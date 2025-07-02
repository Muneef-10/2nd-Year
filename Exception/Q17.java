import java.util.Scanner;

class MyException extends Exception
{
    MyException(String message)
    {
        super(message);
    }
}
class MyCalculator 
{
    int power(int n,int p)
    {
        return (int)Math.pow(n, p);
    }

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number: ");
        int n=sc.nextInt();
        System.out.print("Enter power: ");
        int p=sc.nextInt();
        MyCalculator obj = new MyCalculator();
        try
        {
            if(n<0 || p<0)
                throw new MyException("n and p should not be negative");
            else if(n==0 || p==0)
                throw new MyException("n and p should not be zero");
            
            int x=obj.power(n, p);
            System.out.println("Ans is: "+x);
        }
        catch(MyException e)
        {
            System.out.println(e.getMessage());
        }
    }
}