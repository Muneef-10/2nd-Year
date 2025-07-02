package student;

public class Student 
{
    private int studentId; 
    private String name; 
    private int age; 
    public Student(int studentId, String name, int age) { 
        this.studentId = studentId; 
        this.name = name; 
        this.age = age; 
    } 
    public String getStudentInfo() { 
        return "Student ID: " + studentId + ",Name: " + name + ",Age: " + age; 
    }
}