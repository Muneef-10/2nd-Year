// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)

#include <bits/stdc++.h>
using namespace std;

void findMaxOccurringAlphabet(vector<char>& arr) {
    vector<int> count(26, 0); 
    
    for (char ch : arr) {
        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;
        }
    }

    int maxFreq = 0;
    char maxChar = ' '; 
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            maxChar = 'a' + i;
        }
    }
    cout << "Alphabet '" << maxChar <<"' has maximum occurence that is: "<<maxFreq<<endl;
}

int main() 
{
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<char> v(size);
    for (int i = 0; i < size; i++)
        cin>>v[i];
    
    findMaxOccurringAlphabet(v);

    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
    return 0;
}