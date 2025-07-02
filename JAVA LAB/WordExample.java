public class WordExample 
{
    private String strdata;

    // Parameterized Constructor
    public WordExample(String str) {
        // Validate the sentence ending
        if (!str.endsWith(".") && !str.endsWith("?") && !str.endsWith("!")) {
            throw new IllegalArgumentException("Sentence must end with '.', '?' or '!' ");
        }
        this.strdata = str.trim();
    }

    // Method to count words that begin and end with a vowel
    public void countWord() {
        String[] words = strdata.split("\s+");
        int count = 0;
        
        for (String word : words) {
            word = word.replaceAll("[^A-Z]", ""); // Remove punctuation
            if (word.length() > 0 && isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1))) {
                count++;
            }
        }
        System.out.println("Number of words beginning and ending with a vowel: " + count);
    }

    // Method to reorder words
    public void placeWord() {
        String[] words = strdata.split("\s+");
        StringBuilder vowelWords = new StringBuilder();
        StringBuilder otherWords = new StringBuilder();

        for (String word : words) {
            String cleanWord = word.replaceAll("[^A-Z]", ""); // Remove punctuation
            if (cleanWord.length() > 0 && isVowel(cleanWord.charAt(0)) && isVowel(cleanWord.charAt(cleanWord.length() - 1))) {
                vowelWords.append(cleanWord).append(" ");
            } else {
                otherWords.append(cleanWord).append(" ");
            }
        }
        
        String reorderedSentence = vowelWords.toString() + otherWords.toString();
        System.out.println("Reordered sentence: " + reorderedSentence.trim());
    }

    // Helper method to check if a character is a vowel
    private boolean isVowel(char ch) {
        return "AEIOU".indexOf(ch) != -1;
    }

    public static void main(String[] args) {
        WordExample example = new WordExample("APPLE IS AN ORANGE! PEAR OVAL AI A EE.");
        example.countWord();
        example.placeWord();
    }
}
