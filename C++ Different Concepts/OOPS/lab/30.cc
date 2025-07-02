//Write a program to count number of characters, words and lines in a file.
#include <bits/stdc++.h>
using namespace std;

void countFileContents(const string &filePath) {
    ifstream file(filePath);

    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length(); // Count characters in the line
        
        // Count words in the line
        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) {
            wordCount++; // Add last word in the line
        }

        // Include newline characters in character count
        charCount++;
    }

    file.close();

    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of characters (including newlines): " << charCount << endl;
}

int main() {
    string filePath;
    cout << "Enter the file path: ";
    cin >> filePath;


    countFileContents(filePath);

    return 0;
}
