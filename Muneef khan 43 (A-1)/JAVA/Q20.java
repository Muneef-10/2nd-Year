class SharedResource {
    private int value;
    private boolean isProduced = false;

    public synchronized void produce(int value) throws InterruptedException {
        while (isProduced) {
            wait();
        }
        this.value = value;
        isProduced = true;
        System.out.println("Produced: " + value);
        notify();
    }

    public synchronized void consume() throws InterruptedException {
        while (!isProduced) {
            wait();
        }
        System.out.println("Consumed: " + value);
        isProduced = false;
        notify();
    }
}

class Producer extends Thread {
    private SharedResource sharedResource;
    private int count = 0;

    public Producer(SharedResource sharedResource) {
        this.sharedResource = sharedResource;
    }

    public void run() {
        int value = 0;
        try {
            while (count < 4) {
                sharedResource.produce(value++);
                count++;
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer extends Thread {
    private SharedResource sharedResource;
    private int count = 0;

    public Consumer(SharedResource sharedResource) {
        this.sharedResource = sharedResource;
    }

    public void run() {
        try {
            while (count < 4) { // Stop after 4 consumptions
                sharedResource.consume();
                count++;
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Main {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource();
        Producer producer = new Producer(sharedResource);
        Consumer consumer = new Consumer(sharedResource);
        producer.start();
        consumer.start();
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
    }
}