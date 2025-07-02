import java.util.ArrayList; 
import java.util.List; 
import java.util.Scanner; 
public class Q23 { 
    public static List<Integer> alternate(List<Integer> list1, List<Integer> list2) { 
        List<Integer> result = new ArrayList<>(); 
        int size1 = list1.size(); 
        int size2 = list2.size(); 
        int minSize = Math.min(size1, size2); 
        for (int i = 0; i < minSize; i++) { 
            result.add(list1.get(i)); 
            result.add(list2.get(i)); 
        } 
 
        if (size1 > size2) { 
            result.addAll(list1.subList(minSize, size1)); 
        } else if (size2 > size1) { 
            result.addAll(list2.subList(minSize, size2)); 
        } 
 
        return result; 
    } 
 
    public static void main(String[] args) { 
        Scanner scanner = new Scanner(System.in); 
 
        List<Integer> list1 = new ArrayList<>(); 
        List<Integer> list2 = new ArrayList<>(); 
 
        System.out.print("Enter number of elements in first list: "); 
        int n1 = scanner.nextInt(); 
        System.out.println("Enter " + n1 + " integers for the first list:"); 
        for (int i = 0; i < n1; i++)
            list1.add(scanner.nextInt()); 
 
        System.out.print("Enter number of elements in second list: "); 
        int n2 = scanner.nextInt(); 
        System.out.println("Enter " + n2 + " integers for the second list:"); 
        for (int i = 0; i < n2; i++) { 
            list2.add(scanner.nextInt()); 
        } 
 
        List<Integer> result = alternate(list1, list2); 
        System.out.println("Resulting list after alternating:"); 
        System.out.println(result); 
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        scanner.close(); 
    } 
} 