#include<iostream>
using namespace std;
class Student //Student is a new data type
{
public:
    string name;
    int rno;
    float gpa;
    Student () //Default Constructor
    {

    }
    Student(string s, int rn, float g)    //Parameterised Constructor
    {
        name = s;
        rno = rn;
        gpa = g;
    }
};
int main()
{
    Student s1("Muneef Khan",48,9.23);
    Student s2("Abcde",35,8.2);
    // s1.name="Muneef";
    // s1.rno=48;
    // s1.gpa=9.23;

    //Student s2;
    // s2.name="Himanshu";
    // s2.rno=88;
    // s2.gpa=8.2;

    cout<<s1.name<<" "<<s1.gpa<<" "<<s1.rno<<endl;
    cout<<s2.name<<" "<<s2.gpa<<" "<<s2.rno<<endl;
 
} 