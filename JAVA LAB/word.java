// public class word {
//     private String strdata;

//     public Word(String str)
//     {
//         if(!str.endsWith(".") && !str.endsWith("?")&& !str.endsWith("!"))
//             throw new IllegalArgumentException("Sentence must end with '.', '?' or '!' ");
//         this.strdata = str.trim();
//     }

//     public void countWord()
//     {
//         String[] words = strdata.split("\s+");
//         int count = 0;

//         for (String word : words) 
//         {
//             word=word.replaceAll("[^A-Z]", "")
//             if(word.length()>0 && isVowel(word.charAt(0))&& isVowel(word.charAt(word.length()-1)))
//                 count++;
//         }
//     }
// }
