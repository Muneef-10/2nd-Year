import java.util.ArrayList; 
import java.util.Scanner; 
 
public class Q21 { 
     
    public static void removeEvenLength(ArrayList<String> list) 
    { 
        for (int i = list.size() - 1; i >= 0; i--) 
        { 
            if (list.get(i).length() % 2 == 0) 
            { 
                list.remove(i); 
            } 
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
            String word = scanner.nextLine(); 
            words.add(word); 
        } 
        removeEvenLength(words); 
        System.out.println("List after removing even-length words:"); 
        for (String word : words) { 
            System.out.println(word); 
        } 

        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        scanner.close(); 
    } 
} 