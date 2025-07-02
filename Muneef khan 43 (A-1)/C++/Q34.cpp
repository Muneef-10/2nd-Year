/*Write a program that uses a map to store student names and their corresponding scores. The program should:
• Allow the user to add a student and score.
• Search for a student by name and display their score.
• Update the score of a student if the student is already present in the map.*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> studentScores;
    int c;
    do
    {
        cout << "Enter [1] to add Student." << endl;
        cout << "Enter [2] to search Student." << endl;
        cout << "Enter [3] to update Score of Student." << endl;
        cout << "Enter [0] to exit." << endl;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "Enter name" << endl;
            string name;
            cin >> name;
            cout << "Enter Score" << endl;
            int score;
            cin >> score;
            studentScores[name] = score;
            break;
        }
        case 2:
        {
            cout << "Enter name to search" << endl;
            string name;
            cin >> name;
            if (studentScores.find(name) != studentScores.end())
            {
                cout << "Score of " << name << ":" << studentScores[name] << endl;
            }
            else
            {
                cout << "Student not found" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter name to update score of" << endl;
            string name;
            cin >> name;
            cout << "Enter new score" << endl;
            int score;
            cin >> score;
            if (studentScores.find(name) != studentScores.end())
            {
                studentScores[name] = score;
                cout << "Updated score of " << name << endl;
            }
            else
            {
                cout << "Student not found" << endl;
            }
            break;
        }
        }
    } while (c != 0);
    cout << "*************************************************************************************" << endl;
    cout<< "Program Prepared and Executed by: Muneef Khan, CSE3(A1), Roll no: 43, Section: A1 " << endl;
    cout<< "*************************************************************************************" << endl;
    
    return 0;
}
