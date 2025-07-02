// The problem to rearrange positive and negative numbers in an array . 
import java.util.*;
class Q6
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < arr.length; i++)
            arr[i]=sc.nextInt();
        int j=0;
        for (int i = 0; i <arr.length; i++)
        {
            if(arr[i]<0)
            {
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
                j++;
            }
            else continue;
        }
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");
        
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43");
        System.out.println("*************************************************************");
        sc.close();
    }    
}
