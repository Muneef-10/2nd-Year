class A extends Thread
{
    public void run()
    {
        int i;
        for ( i = 0; i <=500; i++) {
            System.out.println("Thread printing "+i);
        }
        System.out.println("End of thread A");
    }
}
class B extends Thread
{
    public void run()
    {
        int i;
        for ( i = 0; i <=500; i++) {
            System.out.println("Thread printing "+i);
        }
        System.out.println("End of thread B");
    }
}
class C extends Thread
{
    public void run()
    {
        int i;
        for ( i = 0; i <=500; i++) {
            System.out.println("Thread printing "+i);
        }
        System.out.println("End of thread C");
    }
}
public class Multitasking 
{
    public static void main(String[] args) 
    {
        System.out.println("Main thread start");
        A objA = new A();    
        B objB = new B();    
        C objC = new C();  
        
        objA.start();
        objB.start();
        objC.start();

        System.out.println("End of main thread");
    }    
}
