import java.util.ArrayList; 
import java.util.Scanner; 
 
public class Q22 { 
 
    public static void swapPairs(ArrayList<String> list) { 
        for (int i = 0; i < list.size() - 1; i += 2) { 
            String temp = list.get(i); 
            list.set(i, list.get(i + 1)); 
            list.set(i + 1, temp); 
        } 
    } 
 
    public static void main(String[] args) { 
        Scanner scanner = new Scanner(System.in); 
        ArrayList<String> words = new ArrayList<>(); 
 
        System.out.print("Enter number of words: "); 
        int n = scanner.nextInt(); 
        scanner.nextLine();
 
        System.out.println("Enter " + n + " words:"); 
        for (int i = 0; i < n; i++) { 
            words.add(scanner.nextLine()); 
        } 
 
        System.out.println("Before swap: " + words); 
        swapPairs(words); 
        System.out.println("After swap: " + words); 
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        scanner.close(); 
} 
} 