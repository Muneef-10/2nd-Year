class CSthread extends Thread { 
    private int count = 0; 
    public void run() { 
        while (count < 5) { 
            try { 
                Thread.sleep(500);   
            } catch (InterruptedException e) { 
                e.printStackTrace(); } 
            count++; 
            System.out.println("CSthread - Execution count: " + count); 
        } 
    }} 
class ITthread extends Thread { 
    private int count = 0; 
    public void run() { 
        while (count < 5) { 
            try { 
                Thread.sleep(500);   
            } catch (InterruptedException e) { 
                e.printStackTrace(); } 
            count++; 
            System.out.println("ITthread - Execution count: " + count); 
        }}} 
class MultiThreads { 
    public static void main(String[] args) { 
        CSthread csThread = new CSthread(); 
        ITthread itThread = new ITthread();         
        csThread.setName("CSthread"); 
        itThread.setName("ITthread"); 
        csThread.start(); 
        itThread.start(); 
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
    }}