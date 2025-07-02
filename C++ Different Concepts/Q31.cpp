/*Design and implement a system that allows users to manage student records by performing operations such as adding, searching, deleting, and displaying records. Use file handling to store and manipulate data persistently in a text file.*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Student
{
private:
    int rollNumber;
    string name;
    int age;
    string course;

public:
    void inputStudentDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
    }
    void displayStudentDetails() const
    {
        cout << "Roll Number: " << rollNumber << "\nName: " << name
             << "\nAge: " << age << "\nCourse: " << course << "\n";
    }
    void saveToFile() const
    {
        ofstream outFile("students.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << rollNumber << " " << name << " " << age << " " << course << endl;
            outFile.close();
            cout << "Student record added successfully.\n";
        }
        else
        {
            cout << "Error: Unable to open file.\n";
        }
    }
    static void searchStudent(int rollNo)
    {
        ifstream inFile("students.txt");
        string line;
        bool found = false;
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                Student s;
                stringstream ss(line);
                ss >> s.rollNumber >> ws;
                getline(ss, s.name, ' ');
                ss >> s.age >> ws;
                getline(ss, s.course);
                if (s.rollNumber == rollNo)
                {
                    cout << "\nRecord Found:\n";
                    s.displayStudentDetails();
                    found = true;
                    break;
                }
            }
            inFile.close();
            if (!found)
            {
                cout << "Record not found.\n";
            }
        }
        else
        {
            cout << "Error: Unable to open file.\n";
        }
    }
    static void dltStudent(int rollNo)
    {
        ifstream inFile("students.txt");
        ofstream tempFile("temp.txt");
        string line;
        bool found = false;
        if (inFile.is_open() && tempFile.is_open())
        {
            while (getline(inFile, line))
            {
                Student s;
                stringstream ss(line);
                ss >> s.rollNumber >> ws;
                getline(ss, s.name, ' ');
                ss >> s.age >> ws;
                getline(ss, s.course);
                if (s.rollNumber != rollNo)
                {
                    tempFile << line << endl;
                }
                else
                {
                    found = true;
                }
            }
            inFile.close();
            tempFile.close();
            remove("students.txt");
            rename("temp.txt", "students.txt");
            if (found)
            {
                cout << "Record deleted successfully.\n";
            }
            else
            {
                cout << "Record not found.\n";
            }
        }
        else
        {
            cout << "Error: Unable to open file.\n";
        }
    }
    static void displayAllStudents()
    {
        ifstream inFile("students.txt");
        string line;
        if (inFile.is_open())
        {
            cout << "\nAll Student Records:\n";
            while (getline(inFile, line))
            {
                Student s;
                stringstream ss(line);
                ss >> s.rollNumber >> ws;
                getline(ss, s.name, ' ');
                ss >> s.age >> ws;
                getline(ss, s.course);
                s.displayStudentDetails();
                cout << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error: Unable to open file.\n";
        }
    }
};
int main()
{
    int choice;
    do
    {

        cout << "*****Student Record Management System*****\n";
        cout << "Press [1] add Student\nPress [2] to Search Student\nPress [3] Delete Student\nPress [4] Display All Students\nPress [5] to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Student s;
            s.inputStudentDetails();
            s.saveToFile();
            break;
        }
        case 2:
        {
            int rollNo;
            cout << "Enter Roll Number to Search: ";
            cin >> rollNo;
            Student::searchStudent(rollNo);
            break;
        }
        case 3:
        {
            int rollNo;
            cout << "Enter Roll Number to Delete: ";
            cin >> rollNo;
            Student::dltStudent(rollNo);
            break;
        }
        case 4:
            Student::displayAllStudents();
            break;
        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
    return 0;
}
