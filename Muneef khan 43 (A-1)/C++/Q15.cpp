// Write a C++ program to declare a class. Declare pointer to class. Initialize and display the contents of the class member. 

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}
    void display()
    const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

int main() 
{
    Student *ptr;

    ptr = new Student("Abhishek", 20);
    ptr->display();
    delete ptr;

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;

    return 0;
}
