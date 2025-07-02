//Custom Exception

import java.util.Scanner;

class MyException extends Exception
{
    public MyException(String message)
    {
        super(message);
    }
}
class Q4CustomException 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Age: ");
        try{
        int age=sc.nextInt();
        if(age>100)
        {
            throw new MyException("Age is over 100");
        }
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        sc.close();
    }   
}