/*Q-12)Anna is competing to be the top student in her high school. She wants to know how many of her classmates scored higher than she did on their exams
this semester.
You need to create a class named Student with the following features:
Data Members:
An array scores[5] that stores a student's scores for 5 exams.
Member Functions:
A void input() function that reads 5 exam scores and stores them in the scores array.
An int calculateTotalScore() function that calculates and returns the sum of the scores in 
the scores array.*/

#include <iostream>
using namespace std;

class Student {
private:
    int scores[5];

public:
    void input() {
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }

    int calculateTotalScore() {
        int totalScore = 0;
        for (int i = 0; i < 5; i++) {
            totalScore += scores[i];
        }
        return totalScore;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

   
    for (int i = 0; i < n; i++) {
        cout << "Enter the scores for student " << i + 1 << ": ";
        students[i].input();
    }

    int annaScore = students[0].calculateTotalScore();


    int count = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].calculateTotalScore() > annaScore) {
            count++;
        }
    }

    cout << "Number of students who scored higher than Anna: " << count << endl;

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;

    return 0;
}
