#include <fstream>
#include <iostream>

using namespace std;

int year2024_day13_puzzle3() {
    ifstream f("ressources/Year2024/day13/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    while(getline(f, s)) {

    }

    return 0;
}
