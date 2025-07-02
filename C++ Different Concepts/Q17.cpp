/*Q17. Create a student database system where each student has attributes like name, roll number, course, and marks. The program should:
• Use a class Student to store student details.
• Use a pointer to a Student object to dynamically manage student records.
• Allow the user to add, delete, and view student records.
• Calculate and display the average marks of all students.
• Find and display the student with the highest marks.*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string course;
    float marks;

public:
    Student(string n = "", int r = 0, string c = "", float m = 0.0) 
        : name(n), rollNumber(r), course(c), marks(m) {}

    void addStudentDetails(string n, int r, string c, float m) {
        name = n;
        rollNumber = r;
        course = c;
        marks = m;
    }

    void displayStudentDetails() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber
                  << ", Course: " << course << ", Marks: " << marks << endl;
    }

    float getMarks() const {
        return marks;
    }

    bool hasRollNumber(int roll) const {
        return rollNumber == roll;
    }
};

float calculateAverageMarks(Student* students[], int studentCount) {
    float totalMarks = 0;
    for (int i = 0; i < studentCount; ++i) {
        totalMarks += students[i]->getMarks();
    }
    return studentCount > 0 ? totalMarks / studentCount : 0;
}

void displayTopStudent(Student* students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No student records available." << endl;
        return;
    }

    Student* topStudent = students[0];
    for (int i = 1; i < studentCount; ++i) {
        if (students[i]->getMarks() > topStudent->getMarks()) {
            topStudent = students[i];
        }
    }

    cout << "Student with the highest marks:\n";
    topStudent->displayStudentDetails();
}

int main() {
    const int MAX_STUDENTS = 100;
    Student* students[MAX_STUDENTS];
    int studentCount = 0;

    int choice;
    while (true) {
        cout << "\n--- Student Database System ---" << endl;
        cout << "1. Add student record" << endl;
        cout << "2. Delete student record" << endl;
        cout << "3. View all student records" << endl;
        cout << "4. Calculate average marks" << endl;
        cout << "5. Display student with highest marks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Exit..." << endl;
            break;
        }

        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Cannot add more students. Database is full." << endl;
                    break;
                }

                string name, course;
                int rollNumber;
                float marks;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter roll number: ";
                cin >> rollNumber;

                cout << "Enter course: ";
                cin.ignore();
                getline(cin, course);

                cout << "Enter marks: ";
                cin >> marks;

                students[studentCount] = new Student(name, rollNumber, course, marks);
                studentCount++;

                cout << "Student record added successfully!" << endl;
                break;
            }

            case 2: {
                if (studentCount == 0) {
                    cout << "No student records to delete." << endl;
                    break;
                }

                int rollNumber;
                cout << "Enter roll number of the student to delete: ";
                cin >> rollNumber;

                bool found = false;
                for (int i = 0; i < studentCount; ++i) {
                    if (students[i]->hasRollNumber(rollNumber)) {
                        delete students[i]; 
                        for (int j = i; j < studentCount - 1; ++j) {
                            students[j] = students[j + 1]; 
                        }
                        studentCount--;
                        found = true;
                        cout << "Student record deleted successfully!" << endl;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student with roll number " << rollNumber << " not found." << endl;
                }
                break;
            }

            case 3: {
                if (studentCount == 0) {
                    cout << "No student records available." << endl;
                } else {
                    cout << "Student records:\n";
                    for (int i = 0; i < studentCount; ++i) {
                        students[i]->displayStudentDetails();
                    }
                }
                break;
            }

            case 4: {
                float averageMarks = calculateAverageMarks(students, studentCount);
                cout << "Average marks of all students: " << averageMarks << endl;
                break;
            }

            case 5: {
                displayTopStudent(students, studentCount);
                break;
            }

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    for (int i = 0; i < studentCount; ++i) {
        delete students[i];
    }

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}
