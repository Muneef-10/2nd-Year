import java.io.*;

public class PalindromeCounter {
    public static void main(String[] args) {
        int count = 0;

        try 
        {
            BufferedReader reader = new BufferedReader(new FileReader("myfile.txt"));
            String line;

            while ((line = reader.readLine()) != null) {
                // Split line into words
                String[] words = line.split("\\s+");

                for (String word : words) 
                {
                    String cleanWord = word.replaceAll("[^a-zA-Z]", ""); // remove punctuation
                    if (isPalindrome(cleanWord))
                    {
                        count++;
                    }
                }
            }

            reader.close();

            System.out.println("Number of palindromes: " + count);
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    // Method to check if a word is palindrome (case-insensitive)
    public static boolean isPalindrome(String word) {
        word = word.toLowerCase();
        int i = 0, j = word.length() - 1;

        while (i < j) {
            if (word.charAt(i) != word.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        return word.length() > 0; // only count non-empty palindromes
    }
}
