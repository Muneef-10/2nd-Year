import java.util.*; 
class NegativeException extends RuntimeException { 
    public NegativeException(String message){ 
        super(message); 
    } 
} 
class ZeroException extends RuntimeException { 
    public ZeroException(String message){ 
        super(message); 
    } 
} 
class MyCalculator { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter base: "); 
        int n = sc.nextInt(); 
        System.out.print("Enter power: "); 
        int p = sc.nextInt(); 
        try { 
            if (n < 0 || p < 0) { 
                throw new NegativeException("java.lang.Exception: n or p should not be negative."); 
            } else if (n == 0 && p == 0) { 
                throw new ZeroException("java.lang.Exception: n and p should not be zero"); 
            } else { 
                System.out.println(n + "^" + p + " = " + Math.pow(n, p)); 
            } 
        } catch (NegativeException e) { 
            System.out.println(e.getMessage());        } 
        catch (ZeroException e) { 
            System.out.println(e.getMessage());        } 
            
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
    
}}