import java.util.Scanner;

public class Q1 
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

        for (int i = 0; i < r; i++) 
        {
            int min=matrix[i][0], col=0;
            for (int j = 1; j < c; j++) 
            {
                if(min>matrix[i][j])
                {
                    min=matrix[i][j];
                    col=j;
                }
            }

            boolean IsSaddle=true;
            for (int k = 0; k < r; k++) 
            {
                if(min < matrix[k][col])
                {
                    IsSaddle=false;
                    break;
                }
            }

            if(IsSaddle)
            {
                System.out.println("Yes"+ min);
                found=true;
                break;
            }
            
        }
        if(!found) System.out.println("No");
    }
}
