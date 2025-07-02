/*Create a Java program to perform survey on four different model of Maruti (Maruti-K10, Zen-Astelo, Wagnor, Maruti- SX4) owned by person living in four metro 
cities(Delhi, Mumbai, Chennai & Kolkatta). Display tabulated report like format given below: */

#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    const int numModels = 4;
    const int numCities = 4;
    string carModels[numModels] = {"Maruti-K10", "Zen-Astelo", "WagonR", "Maruti-SX4"};
    string cities[numCities] = {"Delhi", "Mumbai", "Chennai", "Kolkata"};
    int surveyData[numModels][numCities] = {0};

    cout << "Enter the number of cars owned for each model in each city:\n";
    for (int i = 0; i < numModels; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cout << "Enter the number of " << carModels[i] << " owned in " << cities[j] << ": ";
            cin >> surveyData[i][j];
        }
    }

    cout << "\n\n\t\t\t\t---- Survey Report ----\n\n";
    
    cout << setw(15) << "Cities";
    for(auto it:carModels){
        cout << setw(15) << it;
    } 
    cout << endl;
    for (int i = 0; i < numModels; ++i) {
        cout << setw(15) << cities[i];
        for (int j = 0; j < numCities; ++j) {
            cout << setw(15) << surveyData[i][j];  
        }
        cout << endl;  
    }

    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
    
    return 0;
}
