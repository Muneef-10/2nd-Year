// Program to find all the patterns of 0(1+)0 in the given string. Given a string containing 0's and 1's, find the total number of 0(1+)0 patterns in the string and output it.0(1+)0 - There should be at least one '1' between the two 0's. 

import java.util.*;

public class Q8 
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter string: ");
        String str=sc.nextLine();
        
        int i=0,n=str.length(),j=0,count=0;
        while (i<n)
        {
            if(str.charAt(i)=='0')
            {
                boolean found=false;
                j=i+1;
               
                while(j<n && str.charAt(j)=='1')
                {
                    found=true;
                    j++;
                }
                if(j<n && str.charAt(j)=='0' && found)
                {
                    i=j;
                    count++;
                }
                else i++;
            }
            else i++;
        
        }
        System.out.println("Count: "+count);
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");
        sc.close();
    }    
}