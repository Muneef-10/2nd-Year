import java.util.Scanner;

class Q11_3D {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number of courses");
        int row = sc.nextInt();

        int course[][] = new int[row][];
        for (int i = 0; i < row; i++) {
            System.out.println("Enter no of student in course " + (i + 1));
            int col = sc.nextInt();
            course[i] = new int[col];
            System.out.println("Enter marks of student in course " + (i + 1));
            for (int j = 0; j < col; j++) {
                course[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < row; i++) {
            int maxMark = 0, sum = 0;
            System.out.print("Marks in course " + (i + 1)+": ");
            for (int j = 0; j < course[i].length; j++) {
                System.out.print(course[i][j] + " ");
                sum += course[i][j];
                if (course[i][j] > maxMark) {
                    maxMark = course[i][j];
                }
            }
            System.out.println();
            // System.out.println("Average marks in course is " + (double)sum / course[i].length);
            System.out.printf("Average marks in course is %.3f%n", (double)sum / course[i].length);
            System.out.println("Highest marks in course is " + maxMark);

        }
        sc.close();
    }
}