import course.Course; 
import enrollment.Enrollment; 
import student.Student; 
import java.util.Scanner; 
 
public class Main { 
    public static void main(String[] args) { 
        Scanner scanner = new Scanner(System.in); 
        System.out.print("Enter Student ID: "); 
        int studentId = scanner.nextInt(); 
        scanner.nextLine(); 
        System.out.print("Enter Student Name: "); 
        String studentName = scanner.nextLine(); 
        System.out.print("Enter Student Age: "); 
        int studentAge = scanner.nextInt(); 
        Student student = new Student(studentId, studentName, studentAge); 
        System.out.print("Enter Course ID: "); 
        int courseId = scanner.nextInt(); 
        scanner.nextLine(); 
        System.out.print("Enter Course Name: ");
        String courseName = scanner.nextLine(); 
        System.out.print("Enter Course Credits: "); 
        int credits = scanner.nextInt(); 
        Course course = new Course(courseId, courseName, credits); 
        Enrollment enrollment = new Enrollment(student, course); 
        System.out.println("\n" + student.getStudentInfo()); 
        System.out.println("\n" + course.getCourseInfo()); 
        System.out.println("\n" + enrollment.getEnrollmentInfo()); 
        scanner.close();
        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
}
}