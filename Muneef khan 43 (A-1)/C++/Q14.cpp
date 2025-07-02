/*Q-14). Develop a class Score that tracks a player's score in a game. Implement the following:
1.Data Member:
    An int data member to store the score.
2.Constructors:
    A default constructor to initialize the score to 0.
    A parameterized constructor to initialize the score to a specific value.
3.Overloaded Operators:
    Overload the pre-increment (++) operator to increase the score by 10 points and return the updated object.
    Overload the post-increment (++) operator to increase the score by 10 points but return the original object before the increment.
4.Main Function:
    Create a Score object, demonstrate the use of both pre-increment and post-increment operators, and display the score after each operation.*/

#include <iostream>
using namespace std;

class Score {
private:
    int score;

public:
    Score() : score(0) {}
    Score(int s) : score(s) {}

    Score& operator++() {
        score += 10;
        return *this;
    }

    Score operator++(int) {
        Score temp = *this;
        score += 10;
        return temp; 
    }
    void display() const {
        cout << "Current Score: " << score << endl;
    }
};

int main() {
    Score s1;
    s1.display();

    ++s1; 
    cout << "After pre-increment: ";
    s1.display();

    s1++;
    cout << "After post-increment: ";
    s1.display(); 

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;

    return 0;
}
