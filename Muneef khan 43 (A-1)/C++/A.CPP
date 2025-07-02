#include <iostream>
using namespace std;

class Base {
public:
    int pubvar;
protected:
    int provar;
private:
    int privar;

public:
    Base() {
        pubvar = 1;
        provar = 2;
        privar = 3;
    }

    void displaybase() {
        cout << "Base class variable values" << endl;
        cout << "Public variable: " << pubvar << endl;
        cout << "Protected variable: " << provar << endl;
        cout << "Private variable: " << privar << endl;
    }
};

class DerivedPublic : public Base {
public:
    void displayDerivedPublic() {
        cout << "\nPublic Derived class" << endl;
        cout << "Public variable: " << pubvar << endl;       // Accessible
        cout << "Protected variable: " << provar << endl;    // Accessible
        cout << "Private variable does not accessible here" << endl;
    }
};

class DerivedProtected : protected Base {
public:
    void displayDerivedProtected() {
        cout << "\nProtected Derived class" << endl;
        cout << "Public variable: " << pubvar << endl;       // Accessible as protected
        cout << "Protected variable: " << provar << endl;    // Accessible
        cout << "Private variable does not accessible here" << endl;
    }
};

class DerivedPrivate : private Base {
public:
    void displayDerivedPrivate() {
        cout << "\nPrivate Derived class" << endl;
        cout << "Public variable: " << pubvar << endl;       // Accessible as private
        cout << "Protected variable: " << provar << endl;    // Accessible
        cout << "Private variable does not accessible here" << endl;
    }
};

// Grandchild class inheriting from DerivedProtected
class Grandchild : public DerivedProtected {
public:
    void displayGrandchildpro() {
        cout << "\nGrandchild class (from DerivedProtected)" << endl;
        // The following lines should give an error because `pubvar` and `provar` are now protected in DerivedProtected
        cout << "Public variable: " << pubvar << endl;   // Not accessible (protected in DerivedProtected)
        cout << "Protected variable: " << provar << endl; // Not accessible (protected in DerivedProtected)
        cout << "Private variable does not accessible here" << endl;
    }
};

int main() {
    Base baseobj;
    baseobj.displaybase();

    DerivedPublic pubobj;
    pubobj.displayDerivedPublic();

    DerivedProtected proobj;
    proobj.displayDerivedProtected();

    DerivedPrivate priobj;
    priobj.displayDerivedPrivate();

    Grandchild gcobj;
    gcobj.displayGrandchildpro(); // This will show that pubvar and provar are not accessible

    return 0;
}
