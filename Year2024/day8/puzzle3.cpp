#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

#define ACOLYTES 10
#define BLOCKS 202400000

using namespace std;

int year2024_day8_puzzle3() {
    ifstream f("ressources/Year2024/day8/part3.txt");

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
        int newthickness = pyramid[0] * input % ACOLYTES + ACOLYTES;
        for (int& value : pyramid) value += newthickness;
        pyramid.insert(pyramid.begin(), newthickness);
        pyramid.insert(pyramid.end(), newthickness);
    }

    const unsigned long long& size = pyramid.size();
    for (int i = 1; i < size - 1; i++) {
        pyramid[i] -= input * size * pyramid[i] % ACOLYTES;
    }

    cout << accumulate(pyramid.begin(), pyramid.end(), 0) - BLOCKS << endl;
    return 0;
}
