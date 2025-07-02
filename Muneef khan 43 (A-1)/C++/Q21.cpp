/*In a university, a University has multiple Departments. Define a University class that aggregates multiple Department objects. Each department has properties
like name, facultyCount, and headOfDepartment.The university "has" departments, but departments can exist independently.
Note: The University aggregates Department objects, where the departments are part of the university but exist independently (e.g., a department might be 
transferred or merged with another university).*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Department 
{
private:
    string name;
    int facultyCount;
    string headOfDepartment;

public:
    Department(string name, int facultyCount, string headOfDepartment) 
        : name(name), facultyCount(facultyCount), headOfDepartment(headOfDepartment) {}

    void displayInfo() const 
    {
        cout << "Department Name: " << name << endl;
        cout << "Faculty Count: " << facultyCount << endl;
        cout << "Head of Department: " << headOfDepartment << endl;
    }
};

class University 
{
private:
    string universityName;
    vector<Department> departments;

public:
    University(string name) : universityName(name) {}

    void addDepartment(const Department& department) 
    {
        departments.push_back(department);
    }

    void displayDepartments() const 
    {
        cout << "University Name: " << universityName << endl;
        cout << "Departments: " << endl;
        for (const auto& department : departments) 
        {
            department.displayInfo();
            cout << endl;
        }
    }
};

int main() 
{
    Department csDepartment("Computer Science", 30, "Mr. B.P. Dubey");
    Department eeDepartment("Electrical Engineering", 25, "Mr. Himanshu Rai Goyal");
    Department meDepartment("Mechanical Engineering", 20, "Dr. Ajay Kumar Saini");
    
    University myUniversity("Graphic Era Hill University");
    
    myUniversity.addDepartment(csDepartment);
    myUniversity.addDepartment(eeDepartment);
    myUniversity.addDepartment(meDepartment);

    myUniversity.displayDepartments();
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    return 0;
}

