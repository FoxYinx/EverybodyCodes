#include <fstream>
#include <iostream>

using namespace std;

int year2024_day7_puzzle3() {
    ifstream f("ressources/Year2024/day7/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    while (getline(f, s)) {

    }

    return 0;
}
