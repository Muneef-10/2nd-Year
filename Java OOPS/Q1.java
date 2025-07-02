//Create a class named "Person" with a variable age.
// class Student
// {
//     int rollNo;
//     String Name;
//     public static void main(String[] args) 
//     {
//         Student Rohan = new Student();
//         System.out.println(Rohan.rollNo);
//         System.out.println(Rohan.Name);
//     }
// }



class Student
{
    int rollNo;
    String studentName;
    // Student(String name,int rno)
    // {
    //     studentName=name;
    //     rollNo=rno;
    // }
}
public class Q1
{
    public static void main(String[] args)
    {
        Student obj1 = new Student();
        obj1.rollNo=8;
        obj1.studentName="Abhishek";
        System.out.println(obj1.studentName);    
        System.out.println(obj1.rollNo); 

        Student obj2 = new Student();
        obj2.rollNo=10;
        obj2.studentName="Rohan";
        System.out.println(obj2.studentName);    
        System.out.println(obj2.rollNo);  
    }
}