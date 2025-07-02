class Mythread extends Thread
{
    private String name;
    Mythread(String name)
    {
        this.name=name;
    }
    public void run()
    {
        for(int i=1;i<=5;i++)
        {
            System.out.println(name+" count: "+i);
            try
            {
                Thread.sleep(500);
            }
            catch(InterruptedException e)
            {
                System.out.println("Thread Interrupted");
            }
        }
    }
}

// class ITthread extends Thread
// {
//     public void run()
//     {
//         for (int i = 1; i <=5; i++)
//         {
//             System.out.println("ITthread count: "+i);
//             try
//             {
//                 Thread.sleep(500);
//             }
//             catch(InterruptedException e)
//             {
//                 System.out.println("ITthread Interrupted");
//             }
//         }
//     }
// }

class Q19
{
    public static void main(String[] args) 
    {
        Mythread cs=new Mythread("CSthread");
        Mythread it=new Mythread("ITthread");
        
        cs.start();
        it.start();
    }
}