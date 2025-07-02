import java.util.*;
class Q3
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String name[]={"Amit","Anil","Praveen","Sushant","Suhani","None of the above"};
        // int num[]=new int[7],choice;
        int num[]={0,0,0,0,0,0},choice;
        
        do
        {
            System.out.println("1. Amit\n2. Anil\n3. Praveen\n4. Sushant \n5. Suhani\n6. None of the above\n7.Exit\nVote your favourite candidate");
            choice =sc.nextInt();
            switch(choice)
            {
                case 1:
                    num[0]++;
                    System.out.println("Vote successfully counted");
                    break;
                case 2:
                    num[1]++;
                    System.out.println("Vote successfully counted");
                    break;
                case 3:
                    num[2]++;
                    System.out.println("Vote successfully counted");
                    break;
                case 4:
                    num[3]++;
                    System.out.println("Vote successfully counted");
                    break;
                case 5:
                    num[4]++;
                    System.out.println("Vote successfully counted");
                    break;
                case 6:
                    num[5]++;
                    System.out.println("Vote successfully counted");
                    break;
                default:
                    System.out.println("Invalid choice, Enter valid choice");
                    break;
            }
        }while(choice!=7);
        int percentage[]={0,0,0,0,0,0},total=0;
        for (int i = 0; i < 6; i++)
            total=total+num[i];
        System.out.println("Candidate name\tVotes Received\tPercentage of Total Votes Received");
        for(int i=0;i<6;i++)
        {
            percentage[i]=(num[i]/total)*100;
            System.out.println(name[i]+"\t\t\t"+num[i]+"\t\t\t"+percentage[i]);  //CHECK IT HERE AT PERCENTAGE
        }
        sc.close();
    }
}
