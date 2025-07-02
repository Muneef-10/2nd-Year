/*Define a class WordExample having the following description: Data members/instance variables: private String strdata : to store a sentence. Parameterized
Constructor WordExample (String) : Accept a sentence which may be terminated by either’.’, ‘? ’or ’!’ only. The words may be separated by more than one blank
space and are in UPPER CASE. MemberMethods: oid countWord(): Find the number of words beginning and ending with a vowel. void placeWord(): Place the words 
which begin and end with a vowel at the beginning, followed by the remaining words as they occur in the sentence.  */

import java.util.Scanner; 
 
class WordExample { 
 
    private String str; 
 
    public WordExample(String str) { 
        this.str = str.trim(); 
    } 
 
    public void wordCount() { 
        String[] words = str.split("\\s+"); 
        int count = 0;
        for (String word : words) { 
            word = word.replaceAll("[.?!]", ""); 
            if (isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1))) { 
                count++; 
            } 
        } 
        System.out.println("Number of words beginning and ending with a vowel: " + count); 
    } 
 
    public void placeWord() { 
        String[] words = str.split("\\s+"); 
        String vowelWords = ""; 
        String otherWords = ""; 
        for (String word : words) { 
            String cleanWord = word.replaceAll("[.?!]", ""); 
            if (isVowel(cleanWord.charAt(0)) && isVowel(cleanWord.charAt(cleanWord.length() - 1))) { 
                vowelWords += word + " "; 
 
            } else { 
                otherWords += word + " "; 
            } 
        } 
        System.out.println("Rearranged sentence: " + (vowelWords + otherWords).trim()); 
    } 
 
    private boolean isVowel(char ch) { 
        return "AEIOUaeiou".indexOf(ch) != -1; 
    } 
 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter a sentence ending with '.', '?' or '!':"); 
        String sentence = sc.nextLine(); 
        WordExample obj = new WordExample(sentence); 
        obj.wordCount();
        obj.placeWord();
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        sc.close(); 
    } 
} 