//define an exception class "My Nation" that is thrown when a string is not equal  is tpo "jai hind".WAP in C++ that implements this exception.
#include <bits/stdc++.h>
using namespace std;

class MyNation : public exception {
public:
    const char* what() const noexcept override {
        return "String is not 'jai hind'";
    }
};

void checkString(const string& input) {
    if (input != "jai hind" && input!="JAI HIND") {
        throw MyNation();
    }
}

int main() {
    string userInput;

    cout << "Enter a string: ";
    getline(cin, userInput);

    try {
        checkString(userInput);
        cout << "The string matches 'jai hind'.\n";
    } catch (const MyNation& e) {
        cout << e.what() <<"\nstring is: "<<userInput<< endl;
    }

    return 0;
}
