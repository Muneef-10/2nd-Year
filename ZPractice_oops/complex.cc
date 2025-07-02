#include<bits/stdc++.h>
using namespace std;
class Complex
{
    int real;
    int imaginary;
    public:
    Complex(int real,int imaginary)
    {
        this->real=real;
        this->imaginary=imaginary;
    }
    void display()
    {
        cout<<real<<"+i"<<imaginary<<endl;
    }
    Complex()
    {

    }
    Complex operator+(Complex c)
    {
        Complex result;
        result.real=this->real+c.real;
        result.imaginary=this->imaginary+c.imaginary;
        return result;
    }
};
int main()
{
    Complex c1(10,15);
    Complex c2(16,24);
    Complex c3=c1+c2;
    c3.display();
    return 0;
}