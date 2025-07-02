class MyThread extends Thread {
    private String threadName;
    private int executionCount = 0;

    public MyThread(String name) {
        this.threadName = name;
    }

    @Override
    public void run() {
        while (executionCount < 5) { // Change 5 to any number of repetitions
            executionCount++;
            System.out.println("Thread Name: " + threadName + ", Execution Count: " + executionCount);
            try {
                Thread.sleep(500); // Pause for 500 milliseconds
            } catch (InterruptedException e) {
                System.out.println(threadName + " interrupted.");
            }
        }
    }
}

public class MultiThreads {
    public static void main(String[] args) {
        MyThread csThread = new MyThread("CSthread");
        MyThread itThread = new MyThread("ITthread");

        csThread.start();
        itThread.start();
    }
}
