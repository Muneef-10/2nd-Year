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
    float getMarks()
    {
        return marks;
    }
    void setMarks(float m) //setter
    {
        marks=m;
    }
private:
    float marks;//If constructor is in private it is unaccesible in main function.
};
int main()
{
    Student s1(43,"Muneef Khan",95.5);
    cout<<s1.getMarks()<<endl;//Directly print marks  
    s1.setMarks(98.2);
    cout<<s1.getMarks()<<endl;//Directly print marks
    
}