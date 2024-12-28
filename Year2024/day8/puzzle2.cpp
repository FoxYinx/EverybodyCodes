#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

#define ACOLYTES 1111
#define BLOCKS 20240000

using namespace std;

int year2024_day8_puzzle2() {
    ifstream f("ressources/Year2024/day8/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    const int input = stoi(s);

    vector pyramid = {1};

    while (accumulate(pyramid.begin(), pyramid.end(), 0) < BLOCKS) {
        int newthickness = pyramid[0] * input % ACOLYTES;
        for (int& value : pyramid) value += newthickness;
        pyramid.insert(pyramid.begin(), newthickness);
        pyramid.insert(pyramid.end(), newthickness);
    }

    cout << (accumulate(pyramid.begin(), pyramid.end(), 0) - BLOCKS) * pyramid.size() << endl;
    return 0;
}
