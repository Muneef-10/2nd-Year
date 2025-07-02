import java.util.*;

public class Q23
{
    public static List<Integer> Alter(List<Integer> list1,List<Integer> list2)
    {
        List<Integer> list=new ArrayList<>();
        int size1=list1.size();
        int size2=list2.size();
        int minsize=Math.min(size1,size2);
        for (int i = 0; i < minsize; i++) {
            list.add(list1.get(i));
            list.add(list2.get(i));
        }
        if(size1>size2)
        {
            list.addAll(list1.subList(minsize, size1));
        }
        else if(size1<size2)list.addAll(list2.subList(minsize, size2));
        return list;
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        List<Integer> list1=new ArrayList<>();
        List<Integer> list2=new ArrayList<>();
        int n,m;
        System.out.println("Enter size of list1: ");
        n=sc.nextInt();
        System.out.println("Enter size of list2: ");
        m=sc.nextInt();
        sc.nextLine();
        System.out.println("Enter list1:");
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            list1.add(x);
        }
        System.out.println("Enter list2:");
        for (int i = 0; i < m; i++) {
            int x=sc.nextInt();
            list2.add(x);
        }

        List<Integer> list=Alter(list1,list2);
        System.out.println(list);
        
    }
}