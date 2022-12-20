#include <iostream>
#include <fstream>
#include <unordered_set>


using namespace std;

int calcPriorityScore(const char& item) {
    int toAscii = isupper(item) ? 38 : 96; // Convert from ASCII to our desired number
    return int(item) - toAscii;
}

int priSumRepItems(const string &filename) {
    int sum = 0;
    ifstream fileRead(filename);
    string lineText;

    while(getline(fileRead, lineText)) {
        unordered_set<char> comp1;
        for (int i = 0; i < lineText.length()/2; i++) // Add everything in comp 1
            comp1.insert(lineText[i]);
        for (unsigned int i = lineText.length()/2; i < lineText.length(); i++) { // Look through comp 2
            char* item = &lineText[i];
            if(comp1.contains(*item)) {
                sum += calcPriorityScore(*item);
                break;
            }
        }
    }

    fileRead.close();

    return sum;
}

int priSumGroup(const string& filename) {
    int sum = 0;
    ifstream fileRead(filename);
    string lineText;

    while(getline(fileRead, lineText)) {
        unordered_set<char> sack1, sack2;

        for(char item : lineText) // All items in sack1 could be the one
            sack1.insert(item);

        getline(fileRead, lineText);
        for(char item : lineText) {
            if (sack1.contains(item))
                sack2.insert(item);
        }

        getline(fileRead, lineText);
        for(char item : lineText) {
            if(sack2.contains(item)) {
                sum += calcPriorityScore(item);
                break;
            }
        }
    }

    fileRead.close();
    return sum;
}

int main() {
    const string filename = "input03.txt";
    cout << "3rd December" << endl;

    cout << "Silver task\t-\tPriority sum of repeated items: " << priSumRepItems(filename) << std::endl;
    cout << "Gold task\t-\tPriority sum of group items: " << priSumGroup(filename) << std::endl;

    return 0;
}