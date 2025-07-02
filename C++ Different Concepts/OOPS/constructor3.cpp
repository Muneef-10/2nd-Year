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
    Student (int r)
    {
        rno =r;
    }
    Student (string s, int r)
    {
        name=s;
        rno=r;
    }
    Student(string s, int rn, float g)    //Parameterised Constructor
    {
        name = s;
        rno = rn;
        gpa = g;
    }
    Student(int rn,float g, string s)    //Parameterised Constructor
    {
        name = s;
        rno = rn;
        gpa = g;
    }
};
int main()
{
    Student s1("Muneef Khan",48);
    s1.gpa=9.23;
    Student s2;
    s2.name="Himanshu";
    s2.rno=88;
    s2.gpa=6.2;

    Student s3("Gagan",13,9.2);
    Student s5(56,8.5,"Harish");

    Student s4(45);
    s4.name="Shubham";
    s4.gpa=7.2;

    Student s6=s1; // Deep copy
    s6.name="Manish";

    Student s7(s1); // Copy constructor :- deep copy(if use pointer in my word then it is SHALLOW COPY, in the other word when we change s7.name if s1.name changes with it(means single change) then it is shallow copy)
    s7.name="Vijay";

    cout<<s1.name<<"  "<<s1.gpa<<"  "<<s1.rno<<endl;
    cout<<s2.name<<"  "<<s2.gpa<<"  "<<s2.rno<<endl;
    cout<<s3.name<<"  "<<s3.gpa<<"  "<<s3.rno<<endl;
    cout<<s4.name<<"  "<<s4.gpa<<"  "<<s4.rno<<endl;
    cout<<s5.name<<"  "<<s5.gpa<<"  "<<s5.rno<<endl;
    cout<<s6.name<<"  "<<s6.gpa<<"  "<<s6.rno<<endl;
    cout<<s7.name<<"  "<<s7.gpa<<"  "<<s7.rno<<endl;
 
} 