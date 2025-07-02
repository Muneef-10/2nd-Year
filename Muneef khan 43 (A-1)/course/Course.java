package course;

public class Course 
{
    private int courseId; 
    private String courseName; 
    private int credits; 
    public Course(int courseId, String courseName, int credits) { 
        this.courseId = courseId; 
        this.courseName = courseName; 
        this.credits = credits; 
    }
    public String getCourseInfo() { 
        return "Course ID: " + courseId + ",Course Name: " + courseName + ",Credits: " + credits; 
    }
}
