class SharedResource {
    boolean isProducing = true;

    synchronized void produce(int val) {
        try {
            if (!isProducing) {
                wait();
            }
            Thread.sleep(1000);
            System.out.println("Producer Produced: " + val);
            isProducing = false;
            notify();

        } catch (InterruptedException e) {
            //
        }
    }

    synchronized void consume(int val) {
        try {
            if (isProducing) {
                wait();
            }
            Thread.sleep(1000);
            System.out.println("Consumer comsumed: " + val);
            isProducing = true;
            notify();

        } catch (InterruptedException e) {
            //
        }
    }
}

class Producer extends Thread {
    SharedResource s;

    Producer(SharedResource s) {
        this.s = s;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            s.produce(i);
        }
    }
}

class Consumer extends Thread {
    SharedResource s;

    Consumer(SharedResource s) {
        this.s = s;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            s.consume(i);
        }
    }
}

class Main {

    public static void main(String[] args) 
    {
        SharedResource s = new SharedResource();
        Thread p = new Producer(s);
        Thread c = new Consumer(s);

        p.start();
        c.start();
    }
}