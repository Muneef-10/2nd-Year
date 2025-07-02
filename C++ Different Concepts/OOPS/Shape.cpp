//WAP to create a class named shape.In this class we have three sub class circle, tirangle and square each class has 2 member function named draw() and erase().Implement these function using runtime polymorphism concepts.

#include<iostream>
using namespace std;
class Shape
{
    public:
    virtual void draw()
    {
        cout<<"Drawing a shape"<<endl;
    }
    virtual void erase()
    {
        cout<<"Erase a shape"<<endl;
    }
    virtual ~Shape(){}
};
class Circle: public Shape
{
    public:
    void draw()
    {
        cout<<"Drawing a Circle"<<endl;
    }
    void erase()
    {
        cout<<"Erase a Circle"<<endl;
    }
};
class Triangle: public Shape
{
    public:
    void draw()
    {
        cout<<"Drawing a Triangle"<<endl;
    }
    void erase()
    {
        cout<<"Erase a Triangle"<<endl;
    }
};
class Square: public Shape
{
    public:
    void draw()
    {
        cout<<"Drawing a Square"<<endl;
    }
    void erase()
    {
        cout<<"Erase a Square"<<endl;
    }
};
int main()
{
    cout<<"Demonstrate of run time polymorphism using pure virtual method"<<endl;
    Shape *shape;
    shape=new Circle();
    // cout<<'Drawing(shape->draw()) and erasing (shape->erase() Circle)'<<endl;
    shape->draw();
    shape->erase();
    delete shape;

    shape=new Triangle();
    shape->draw();
    shape->erase();
    delete shape;

    shape=new Square();
    shape->draw();
    shape->erase();
    delete shape;





    cout<<"Demonstrate of run time polymorphism using pure virtual method"<<endl;
    Shape *ref;
    Circle obj1;
    Square obj2;
    ref =&obj1;
    ref->draw();
    ref->erase();
    
    return 0;
}