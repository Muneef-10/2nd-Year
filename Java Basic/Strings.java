// import java.util.*;
public class Strings 
{
    public static void main(String[] args) 
    {
        // Scanner sc=new Scanner(System.in);
        // String name=sc.nextLine();
        // System.out.println(name);


        //Concatination

        // String firstname="Tony";
        // String lastname="Stark";
        // String fullname=firstname+lastname;
        // System.out.println(fullname.length() );

        // // charAt

        // for (int i = 0; i < fullname.length(); i++) 
        // {
        //     System.out.println(fullname.charAt(i));
        // }


        // Compare
        
        // String name1="Tony";
        // String name2="Tony2";

        // //1 s1>s2  +ve value
        // //2 s1==s2  0
        // //3 s1<s3  -ve value

        // if(name1.compareTo(name2)==0) System.out.println("Equal");
        // else System.out.println("UnEqual");


        // Substring

        String sentence ="My name is Khan";
        // substring(Beggining, ending index)
        // String name = sentence.substring(11,sentence.length()); //same with below
        String name = sentence.substring(11);
        System.out.println(name);
    }
}