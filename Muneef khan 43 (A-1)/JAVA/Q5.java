//Printing an array into Zigzag fashion. Suppose you were given an array of integers, and you are told to sort the integers in a zigzag pattern. In general, in a zigzag pattern, the first integer is less than the second integer, which is greater than the third integer, which is less than the fourth integer, and so on. Hence, the converted array should be in the form of e1 < e2 > e3 < e4 > e5 < e6.

import java.util.Scanner; 
class Main
{ 
    public static void main(String args[])
    { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter the size of the array: "); 
        int n=sc.nextInt(); 
        int arr[]=new int[n]; 
        System.out.print("Enter the elements of the array: "); 
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt(); 
        for(int i=0;i<n-1;i++){ 
            if(i%2==0){ 
                if(arr[i]>arr[i+1]){ 
                    int temp =arr[i]; 
                    arr[i]=arr[i+1]; 
                    arr[i+1]=temp; 
                } 
            } 
            else{ 
                if(arr[i]<arr[i+1]){ 
                    int temp =arr[i]; 
                    arr[i]=arr[i+1]; 
                    arr[i+1]=temp; 
                } 
            } 
        } 
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+ " "); 

        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
        sc.close();
    }
}