import java.io.*; 
class PalindromeCounter { 
    public static boolean isPalindrome(String word) { 
        word = word.toLowerCase(); 
        int left = 0, right = word.length() - 1; 
        while (left < right) { 
            if (word.charAt(left) != word.charAt(right)) { 
                return false; 
            } 
            left++; 
            right--; 
        } 
        return word.length() >1; 
    } 
    public static void main(String[] args) { 
        int count = 0; 
        try (BufferedReader reader = new BufferedReader(new FileReader("myFile.txt"))) { 
            String line; 
            while ((line = reader.readLine()) != null) { 
                String[] words = line.split("\\W+"); 
                for (String word : words) { 
                    if (isPalindrome(word)) { 
                        count++;  }  }  } 
            System.out.println("Number of palindromes: " + count); 
        } catch (IOException e) { 
            System.out.println("Error reading the file: " + e.getMessage());  } 
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
    } 
}