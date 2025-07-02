package enrollment; 
import course.Course; 
import student.Student; 
 
public class Enrollment { 
    private Student student; 
    private Course course; 
 
    public Enrollment(Student student, Course course) { 
        this.student = student; 
        this.course = course; 
    }
    public String getEnrollmentInfo() { 
        return "Enrollment Details: [ " + student.getStudentInfo() + " | " + course.getCourseInfo() + " ] "; 
    } 
} 