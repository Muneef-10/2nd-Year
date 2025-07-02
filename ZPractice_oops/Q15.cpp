// Write a C++ program to declare a class. Declare pointer to class. Initialize and display the contents of the class member. 
#include<iostream>
using namespace std;
class Student
{
    private:
        string name;
        int age;
    public:
        Student(string n, int a)
        {
            name=n;
            age=a;
        }
        void display()
        {
            cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
        }
};
int main()
{
    Student *ptr=new Student("Abhishek",50);
    ptr->display();
    delete ptr;

    return 0;
}