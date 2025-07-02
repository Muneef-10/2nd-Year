/* Write a program to create a class named shape. In this class we have three sub classes
circle,
triangle and square each class has two member functions named draw () and erase
(). Implements
these functions using runtime polymorphism concepts.*/
#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void draw() {};
    virtual void erase() {};
};
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing circle " << endl;
    }
    void erase()
    {
        cout << "Erasing circle " << endl;
    }
};
class Triangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing triangle " << endl;
    }
    void erase()
    {
        cout << "Erasing triangle " << endl;
    }
};
class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing rectangle " << endl;
    }
    void erase()
    {
        cout << "Erasing rectangle " << endl;
    }
};
int main()
{
    cout << "Run time polymorphism using pure virtual function" << endl;
    Shape *sh;
    Circle c;
    Triangle t;
    Rectangle r;
    cout << "Drawand erase circle using sh->draw() and sh->erase()" << endl;
    sh = &c;
    sh->draw();
    sh->erase();
    cout << "Draw and erase triangle using sh->draw() and sh->erase()" << endl;
    sh = &t;
    sh->draw();
    sh->erase();
    cout << "Draw and erase triangle using sh->draw() and sh->erase()" << endl;
    sh = &r;
    sh->draw();
    sh->erase();
    cout << "*************************************************************************************" << endl;
    cout << "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1" << endl;
    cout << "*************************************************************************************" << endl;
}