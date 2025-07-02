/*Demonstrate the order of execution of constructors and destructors in a multilevel inheritance scenario.*/
#include <iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "Base Constructor Called" << endl;
    }
    ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};
class Derived1 : public Base {
public:
    Derived1() {
        cout << "Derived1 Constructor Called" << endl;
    }
    ~Derived1() {
        cout << "Derived1 Destructor Called" << endl;
    }
};
class Derived2 : public Derived1 {
public:
    Derived2() {
        cout << "Derived Constructor Called" << endl;
    }
    ~Derived2() {
        cout << "Derived Destructor Called" << endl;
    }
};
int main() {
    Derived2 obj;
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;    
    return 0;  
}
