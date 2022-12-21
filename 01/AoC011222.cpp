#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int mostCalsCarried(const string &filename) {
    ifstream fileRead(filename);
    string lineText;

    int mostCals, currCals = 0;

    while (getline(fileRead, lineText)) {
        if (lineText.empty()) {
            mostCals = mostCals > currCals ? mostCals : currCals;
            currCals = 0;
        } else
            currCals += stoi(lineText);
    }

    fileRead.close();

    return mostCals;
}

int totCalsTopk(const string &filename, const int k = 3) {
    ifstream fileRead(filename);
    string lineText;

    priority_queue<int, vector<int>, greater<>> pq;
    int currCals = 0;

    while (getline(fileRead, lineText)) {
        if (lineText.empty()) {
            if (pq.size() < k)
                pq.push(currCals);
            else if (currCals > pq.top()) {
                pq.pop();
                pq.push(currCals);
            }
            currCals = 0;
        } else
            currCals += stoi(lineText);
    }

    fileRead.close();

    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main() {
    const string filename = "input01.txt";
    cout << "1st December" << endl;

    cout << "Silver task\t-\tMost calories Carried by an elf: " << mostCalsCarried(filename) << std::endl;
    cout << "Gold task\t-\tCalories carried by top 3 elves: " << totCalsTopk(filename) << std::endl;

    return 0;
}
