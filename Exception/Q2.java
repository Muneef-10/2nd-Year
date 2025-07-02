class Q2
{
    public static void main(String[] args) 
    {
        int a[]=new int[5];
        System.out.println("Hello world");

        try
        {
            System.out.println(a[8]);
        }
        // catch(Exception e)
        // {
        //     System.out.println("Error Occurred!!");
        // }
        /* Cases where finally block doesn't work
        1) System.exit()
        2) An exception occured in finally block
        3) The dead of thread*/
        finally  
        {
            System.out.println("I will run always");
        }
        System.out.println("Bye world");
    }
}