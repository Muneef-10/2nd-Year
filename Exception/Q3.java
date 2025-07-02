class Q3 
{
    static int getnumber(int a[]) throws ArithmeticException
    {
        return a[8];
    }
    public static void main(String[] args) 
    {
        System.out.println("Hello guys");
        int a[]=new int[5];
        try
        {
            getnumber(a);
        }
        catch(Exception e)
        {
            System.out.println("Error occurred "+e.getMessage());
        }
    }
}
