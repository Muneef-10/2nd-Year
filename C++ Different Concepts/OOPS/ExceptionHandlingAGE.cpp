//Define an exception class called InvalidAgeException that accept user's age and if the age is less than 18 then throw an exception with suitable error message  and catch it by displaying.
#include <bits/stdc++.h>
using namespace std;

class InvalidAgeException : public exception {
private:
    string message;
public:
    InvalidAgeException(int age) {
        message = "Invalid age: " + to_string(age) + " Age must be 18 or above.";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

void checkAge(int age) {
    if (age < 18) {
        throw InvalidAgeException(age);
    } else {
        cout << "Age is valid." << endl;
    }
}

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    try {
        checkAge(age);
    }
    catch (const InvalidAgeException& e) {
        cout << e.what() << endl;
    }
    return 0;
}
