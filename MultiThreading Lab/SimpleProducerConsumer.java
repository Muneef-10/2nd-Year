import java.util.*;

class Buffer 
{
    int data[];
    boolean isEmpty = true;
    
    public synchronized void produce(int value)
    {
        data=new int[10];
        while(!isEmpty)
        {
            try
            {
                wait();
            }catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        for(int i=0;i<data.length;i++)
        {
            data[i] = value;
        }
        
        System.out.println("Producer produced: "+ Arrays.toString(data));
        isEmpty = false;
        notify();
    }

    public synchronized void consume()
    {
        while(isEmpty){
            try{
                wait();
            }catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }

        System.out.println("Consumer comsumed: " + Arrays.toString(data));
        isEmpty = true;
        notify();
    }
}

class Producer extends Thread
{
    Buffer buffer;
    Scanner sc= new Scanner(System.in);
    public Producer(Buffer buffer)
    {
        this.buffer=buffer;
    }

    public void run()
    {
        for(int i=1;i<=5;i++)
        {
            
            buffer.produce(i);
            try{
                Thread.sleep(500);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        sc.close();
    }
}

class Consumer extends Thread{
    Buffer buffer;

    public Consumer(Buffer buffer)
    {
        this.buffer=buffer;
    }
    public void run()
    {
        for(int i=1;i<=5;i++)
        {
            buffer.consume();
            try{
                Thread.sleep(800);
            }catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

public class SimpleProducerConsumer
{
    public static void main(String[] args) {
        Buffer sharedBuffer = new Buffer();
        Producer p = new Producer(sharedBuffer);
        Consumer c = new Consumer(sharedBuffer);

        p.start();
        c.start();
    }
    
}