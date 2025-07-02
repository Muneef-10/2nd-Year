/*Q-6)The daily maximum temperatures recorded in 5 cities during the month of January (for all 31days) have been tabulated as follows:
Write a program to read the table elements into a two-dimensional array temperature, and to find the city and day corresponding to (a) the highest 
temperature and (b) the lowest temperature.*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int numCities = 5;
    const int numDays = 5;
    string cities[numCities] = {"Delhi", "Mumbai", "Kolkata", "Chennai", "Dehradun"};
    int temperature[numCities][numDays];

    cout << "Enter the daily maximum temperatures for the month of January:\n";
    for (int i = 0; i < numCities; ++i) {
        cout << "Enter temperatures for " << cities[i] << ":\n";
        for (int j = 0; j < numDays; ++j) {
            cout << "Day " << (j + 1) << ": ";
            cin >> temperature[i][j];
        }
    }

    int highestTemp = temperature[0][0];
    int lowestTemp = temperature[0][0];
    int highestCityIndex = 0;
    int highestDayIndex = 0;
    int lowestCityIndex = 0;
    int lowestDayIndex = 0;

    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numDays; ++j) {
            if (temperature[i][j] > highestTemp) {
                highestTemp = temperature[i][j];
                highestCityIndex = i;
                highestDayIndex = j;
            }
            if (temperature[i][j] < lowestTemp) {
                lowestTemp = temperature[i][j];
                lowestCityIndex = i;
                lowestDayIndex = j;
            }
        }
    }

    cout << "\nHighest Temperature:\n";
    cout << "City: " << cities[highestCityIndex] << "\n";
    cout << "Day: " << (highestDayIndex + 1) << "\n";
    cout << "Temperature: " << highestTemp << "\n";

    cout << "\nLowest Temperature:\n";
    cout << "City: " << cities[lowestCityIndex] << "\n";
    cout << "Day: " << (lowestDayIndex + 1) << "\n";
    cout << "Temperature: " << lowestTemp << "\n";
    
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}
