#include <iostream>
#include <fstream>

using namespace std;

int testFunc(const string &filename) {
    int sum = 0;

    ifstream fileRead(filename);
    string lineText;

    while (getline(fileRead, lineText)) {

    }

    fileRead.close();
    return sum;
}

int main() {
    const string filename = "";
    cout << "nth December" << endl;

//    cout << "Silver task\t-\tScore according to original strategy: " << scoreOrigStrategy(filename) << std::endl;
//    cout << "Gold task\t-\tScore according to new strategy: " << scoreNewStrategy(filename) << std::endl;

    return 0;
}