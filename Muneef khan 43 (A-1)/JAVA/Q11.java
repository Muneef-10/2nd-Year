/*Write a Java program to create a class called ArrayDemo and overload arrayFunc() function. void arrayFunc(int [], int) ➔To find all pairs of elements in an Array whose sum is equal to a given number void arrayFunc(int A[], int p, int B[], int q)➔Given two sorted arrays A and B of size p and q, Overload method arrayFunc() to merge elements of A with B by maintaining the sorted order i.e. fill A with first p smallest elements and fill B with remaining elements.*/
import java.util.*; 
 
class ArrayDemo 
{ 
    void arrayFunc(int arr[], int target)
    { 
        System.out.println("Pairs of elements whose sum is " + target + " are:"); 
        for (int i = 0; i < arr.length; i++)
        { 
            for (int j = i + 1; j < arr.length; j++)
            { 
                if (arr[i] + arr[j] == target) 
                    System.out.println(arr[i] + " + " + arr[j] + " = " + target); 

            } 
        } 
    } 
    void arrayFunc(int A[], int p, int B[], int q) 
    { 
        int[] C = new int[p + q]; 
        int i = 0, j = 0, k = 0;  
        while (i < p && j < q) 
        { 
            if (A[i] < B[j])
                C[k++] = A[i++]; 
            else
                C[k++] = B[j++]; 
        } 
        while (i < p) { 
            C[k++] = A[i++]; 
        } 
        while (j < q) { 
            C[k++] = B[j++]; 
        } 
        for (i = 0; i < p; i++) { 
            A[i] = C[i]; 
        } 
        for (j = 0; j < q; j++) { 
            B[j] = C[p + j]; 
        } 
        System.out.println("Sorted Arrays:"); 
        System.out.println("A: " + Arrays.toString(A)); 
        System.out.println("B: " + Arrays.toString(B)); 
    }

    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        ArrayDemo obj=new ArrayDemo();
        System.out.print("Enter size of array: ");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter elements in array: ");
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();

        System.out.print("Enter target sum: ");
        int target=sc.nextInt();
        obj.arrayFunc(arr, target);

        System.out.print("Enter size of first sorted array: ");
        int p=sc.nextInt();
        int []A=new int[p];
        System.out.println("Enter elements in first sorted array: ");
        for(int i=0;i<p;i++)
            A[i]=sc.nextInt();

        System.out.print("Enter size of second sorted array: ");
        int q=sc.nextInt();
        int []B=new int[q];

        System.out.println("Enter elements in second sorted array: ");
        for(int i=0;i<q;i++)
            B[i]=sc.nextInt();
            
        obj.arrayFunc(A, p, B, q);
        sc.close();
        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");

    }
}