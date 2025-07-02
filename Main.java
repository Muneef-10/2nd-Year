// class MyButtonHandler extends JFrame implements ActionListener {
//     JButton b = new JButton("Click Me");

//     MyButtonHandler() {
//         b.addActionListener(this); // registering itself
//         add(b);
//         setSize(200,200);
//         setVisible(true);
//     }

//     public void actionPerformed(ActionEvent e) {
//         System.out.println("Button Clicked!");
//     }
// }



class SharedResource
{
    boolean isproducing=true;
    synchronized void produce(int val)
    {
        try
        {
            if(!isproducing)
            wait();

            Thread.sleep(1000);
            System.out.println("Producer "+val);
            isproducing=false;
            notify();
        }
        catch(Exception e)
        {

        }
    }
    synchronized void consume(int val)
    {
        try
        {
            if(isproducing)
            wait();

            Thread.sleep(1000);
            System.out.println("Consumer "+val);
            isproducing=true;
            notify();
        }
        catch(Exception e)
        {

        }
    }
}

class Producer extends Thread
{
    SharedResource s;
    Producer(SharedResource s)
    {
        this.s=s;
    }
    public void run()
    {
        for(int i = 1; i <=5; i++) 
        {
           s.produce(i); 
        }
    }
}
class Consumer extends Thread
{
    SharedResource s;
    Consumer(SharedResource s)
    {
        this.s=s;
    }
    public void run()
    {
        for(int i = 1; i <=5; i++) 
        {
           s.consume(i); 
        }
    }
}

public class Main
{
    public static void main(String args[])
    {
        SharedResource s=new SharedResource();
        Thread p=new Producer(s);
        Thread c=new Consumer(s);
        p.start();
        c.start();
    }
}