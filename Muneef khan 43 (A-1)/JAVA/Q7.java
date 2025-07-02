// Program to find the saddle point coordinates in a given matrix. A saddle point is an element of the matrix, which is the minimum element in its row and the maximum in its column. 
import java.util.*;
public class Q7
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter row and column of matrix:");
        int r=sc.nextInt();
        int c=sc.nextInt();
        boolean found=false;

        int [][] matrix=new int[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                matrix[i][j]=sc.nextInt();
            }
        }
        sc.close();
    
        for(int i=0;i<r;i++)
        {
            int min=matrix[i][0],col_ind=0;
            for(int j=1;j<c;j++)
            {
                if(min>matrix[i][j])
                {
                    min=matrix[i][j];
                    col_ind=j;
                }
            }

            boolean IsSaddle=true;
            for (int k = 0; k < r; k++) 
            {
                if(min < matrix[k][col_ind])
                {
                    IsSaddle=false;
                    break;
                }
            }
            if(IsSaddle)
            {
                System.out.println("Value of Saddle Point is: "+min);
                found=true;
                break;
            }

        }
        if(!found)
            System.out.println("Not found");

        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");

    }
}