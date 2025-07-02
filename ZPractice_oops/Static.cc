#include<bits/stdc++.h>
using namespace std;
class Student
{
    private:
    string name;
    int age;
    static int Max;
    static int total;
    static int total_age;
    public:
    Student(string name,int age)
    {
        this->name=name;
        this->age=age;
        total++;
        total_age=total_age+age;
        if(Max<age) Max=age;
    }
    static void accesStatic()
    {
        cout<<total;
    }
    void display()
    {
        cout<<"Name: "<<name;
        cout<<" Age: "<<age;
        cout<<endl<<"Max age: "<<Max;
        cout<<endl<<total;
        cout<<endl<<total_age;
    }
};
int Student::total=0;
int Student::Max=0;
int Student::total_age=0;
int main()
{
    Student s1("Rohit",25);
    Student s2("Mohit",24);
    Student s3("Romit",23);
    Student s4("Sakib",28);
    Student s5("Arpit",21);
    // s3.display();
    Student::accesStatic();
    // Student::total=10; if total is public then it access
    s3.display();
    return 0;
}