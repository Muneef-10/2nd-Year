import java.util.Scanner;
class MyException extends Exception 
{
    public MyException(String Message)
    {
        super(Message);
    }
    
}

public class Q16
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int id=0,dept_Id=0;
        String name="";
        try
        {
            System.out.print("Enter Id number: ");
            id=sc.nextInt();
            if(id<2001 || id>5001)
                throw new MyException("Employee id should be between 2001 and 5001");

            sc.nextLine();
            System.out.print("Enter name: ");
            name=sc.nextLine();
            if(!Character.isUpperCase(name.charAt(0)))
                throw new MyException("First letter should be capital");

            System.out.print("Enter department id: ");
            dept_Id=sc.nextInt();
            if(dept_Id<1 || dept_Id>5)
                throw new MyException("Department id should be between 1 and 5");

            System.out.println("\nEmployee Details:");
            System.out.println("Id number: "+id);
            System.out.println("Name: "+name);
            System.out.println("Department Id : "+dept_Id);
        }
        catch(MyException e)
        {
            System.out.println(e);
        }
        
    }
}