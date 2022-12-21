#include <iostream>
#include <fstream>

using namespace std;

int numContained(const string &filename) {
    int sum = 0;

    ifstream fileRead(filename);
    string lineText;

    string low1String, high1String, low2String, high2String;
    while (getline(fileRead, low1String, '-')) {
        getline(fileRead, high1String, ',');
        getline(fileRead, low2String, '-');
        getline(fileRead, high2String);

        int low1 = stoi(low1String);
        int high1 = stoi(high1String);
        int low2 = stoi(low2String);
        int high2 = stoi(high2String);

        if ((low1 <= low2 && high1 >= high2) || (low2 <= low1 && high2 >= high1))
            sum++;

    }

    fileRead.close();

    return sum;
}

int numOverlap(const string &filename) {
    int sum = 0;

    ifstream fileRead(filename);
    string lineText;

    string low1String, high1String, low2String, high2String;
    while (getline(fileRead, low1String, '-')) {
        getline(fileRead, high1String, ',');
        getline(fileRead, low2String, '-');
        getline(fileRead, high2String);

        int low1 = stoi(low1String);
        int high1 = stoi(high1String);
        int low2 = stoi(low2String);
        int high2 = stoi(high2String);

        if ((low1 >= low2 && low1 <= high2) || (low2 >= low1 && low2 <= high1) || (high1 <= high2 && high1 >= low2) ||
            (high2 <= high1 && high2 >= low1))
            sum++;

    }

    fileRead.close();
    return sum;
}

int main() {
    const string filename = "input04.txt";
    cout << "4th December" << endl;

    cout << "Silver task\t-\tNumber of contained ranges: " << numContained(filename) << std::endl;
    cout << "Gold task\t-\tNumber of overlapping pairs: " << numOverlap(filename) << std::endl;

    return 0;
}