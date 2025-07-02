class Q1
{
    public static void main(String[] args) 
    {
        int a[]=new int[5];
        System.out.println("Hello guys");
        try
        {
            // int result=5/0;
            
            System.out.println(a[8]);
        }  
        catch(ArrayIndexOutOfBoundsException | ArithmeticException e)
        {
            // System.out.println("Error occurred!!, Try to access the out of bound element");
            System.out.println("Error occurred!!");
        }
        // catch(ArithmeticException e)
        // {
        //     System.out.println("Error occurred!!, Number can't be divide by 0"+e.getMessage()+"\n"+e.getStackTrace());
        // }
        catch(Exception e)
        {
            System.out.println("Error occurred!!");
        }
        
        System.out.println("Bye guys");
    }
}