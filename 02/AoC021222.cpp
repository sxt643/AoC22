#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int scoreOrigStrategy(const string &filename) {
    const int DRAW_SCORE = 3;
    const int WIN_SCORE = 6;
    map<char, int> scoreMap{{'X', 1},
                            {'Y', 2},
                            {'Z', 3},
                            {'A', 1},
                            {'B', 2},
                            {'C', 3}};
    ifstream fileRead(filename);
    string lineText;


    int totalScore = 0;

    while (getline(fileRead, lineText)) {
        int oppMove = scoreMap.at(lineText[0]);
        int myMove = scoreMap.at(lineText[2]);
        totalScore += myMove;
        if (oppMove == myMove) // if draw
            totalScore += DRAW_SCORE;
        else if (myMove - oppMove == 1 || myMove - oppMove == -2) // Player wins
            totalScore += WIN_SCORE;
    }

    fileRead.close();

    return totalScore;
}

int scoreNewStrategy(const string &filename) {
    const int DRAW_SCORE = 3;
    const int WIN_SCORE = 6;
    map<char, int> scoreMap{{'A', 1},
                            {'B', 2},
                            {'C', 3}};
    map<char, int> loseMap{{'A', 3},
                           {'B', 3}};
    ifstream fileRead(filename);
    string lineText;

    int totalScore = 0;

    while (getline(fileRead, lineText)) {
        int oppMove = scoreMap.at(lineText[0]);
        char myMove = lineText[2];

        if (myMove == 'X') // Lose
            totalScore += (oppMove - 1 > 0) ? oppMove - 1 : 3;
        else if (myMove == 'Y') // Draw
            totalScore += oppMove + DRAW_SCORE;
        else if (myMove == 'Z') // Win
            totalScore += 6 + ((oppMove + 1 <= 3) ? oppMove + 1 : 1);

    }

    fileRead.close();

    return totalScore;
}

int main() {
    const string filename = "input02.txt";
    cout << "2nd December" << endl;

    cout << "Silver task\t-\tScore according to original strategy: " << scoreOrigStrategy(filename) << std::endl;
    cout << "Gold task\t-\tScore according to new strategy: " << scoreNewStrategy(filename) << std::endl;

    return 0;
}