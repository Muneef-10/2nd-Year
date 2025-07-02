#include <iostream>
#include <string>
using namespace std;

// Base Class: Student
class Student {
protected:
    int age;
    string name;
    string enroll_no;
    float marks;

public:
    // Constructor to initialize Student data members
    Student(int age, string name, string enroll_no, float marks)
        : age(age), name(name), enroll_no(enroll_no), marks(marks) {}

    // Function to display Student information
    void display() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Enrollment No.: " << enroll_no << endl;
        cout << "Marks: " << marks << endl;
    }
};

// Base Class: Faculty
class Faculty {
protected:
    string facultyName;
    string facultyCode;
    float salary;
    string deptt;
    int age;
    int experience;
    string gender;

public:
    // Constructor to initialize Faculty data members
    Faculty(string facultyName, string facultyCode, float salary, string deptt,
            int age, int experience, string gender)
        : facultyName(facultyName), facultyCode(facultyCode), salary(salary),
          deptt(deptt), age(age), experience(experience), gender(gender) {}

    // Function to display Faculty information
    void display() {
        cout << "Faculty Information:" << endl;
        cout << "Name: " << facultyName << endl;
        cout << "Age: " << age << endl;
        cout << "Faculty Code: " << facultyCode << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << deptt << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Derived Class: Person (Multiple Inheritance from Student and Faculty)
class Person : public Student, public Faculty {
public:
    // Constructor to initialize both Student and Faculty base classes
    Person(int studentAge, string studentName, string enroll_no, float marks,
           string facultyName, string facultyCode, float salary, string deptt,
           int facultyAge, int experience, string gender)
        : Student(studentAge, studentName, enroll_no, marks),
          Faculty(facultyName, facultyCode, salary, deptt, facultyAge, experience, gender) {}

    // Function to display both Student and Faculty information
    void displayAll() {
        // Explicitly call display() from both base classes
        Student::display();
        cout << endl; // Separator for clarity
        Faculty::display();
    }
};

int main() {
    // Create a Person object with both Student and Faculty information
    Person p(20, "John Doe", "EN12345", 88.5, "Dr. Smith", "FAC001", 75000, "Computer Science", 45, 20, "Male");

    // Call the function to display all information
    p.displayAll();

    return 0;
}
