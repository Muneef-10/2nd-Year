import java.util.*;

public class Q21 
{
    public static void removeEven(ArrayList<String> list)
    {
        for(int i=0;i<list.size();i++)
        {
            if(list.get(i).length()%2==0) list.remove(i);
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
        removeEven(words);
        System.out.println();
        for(String word:words)
        {
            System.out.println(word);
        }
    }
}