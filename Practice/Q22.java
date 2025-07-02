import java.util.*;

public class Q22 
{
    public static void swapPair(ArrayList<String> list)
    {
        for (int i = 0; i < list.size(); i=i+2) 
        {
            String temp=list.get(i);    
            list.set(i,list.get(i+1));   
            list.set(i+1,temp);   
        }
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        ArrayList<String> words=new ArrayList<>();
        int n;
        System.out.println("Enter number of words: ");
        n=sc.nextInt();
        sc.nextLine();
        System.out.println("Enter word:");
        for (int i = 0; i < n; i++) {
            String word=sc.nextLine();
            words.add(word);
        }
        System.out.println("BEFORE :"+ words);
        swapPair(words);
        System.out.println("AFTER :"+ words);
    }
}