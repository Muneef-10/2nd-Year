//Program to replace all 0's with 1 in a given integer. Given an integer as an input, all the 0's in the number has to be replaced with 1.
import java.util.Scanner; 
class Main
{ 
    public static void main(String args[])
    { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter the number: "); 
        int n=sc.nextInt(); 
        int ans=0; 
        int t=1; 
        while(n>0)
        { 
            int temp=n%10; 
            if(temp==0)
                temp=1; 
            ans+=temp*t; 
            t*=10; 
            n/=10; 
        } 
        System.out.println(ans);

        System.out.println("*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
        sc.close(); 
    }
}