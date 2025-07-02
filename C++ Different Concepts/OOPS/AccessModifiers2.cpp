#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
    int rno;
    string name;
    Student()
    {

    }
    Student(int rno, string name, float marks)
    {
        this->rno=rno;
        this->name=name;
        this->marks=marks;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll no.: "<<rno<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
private:
    float marks;
};
int main()
{
    Student s1(43,"Muneef Khan",95);
    Student s2(65,"Himanshu",85.8);
    s1.display();
    s2.display();

}