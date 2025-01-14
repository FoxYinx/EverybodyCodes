#include <fstream>
#include <iostream>
#include <vector>
#include "DisjointSet.h"
#include "kruskal.h"

using namespace std;

int year2024_day17_puzzle3() {
    ifstream f("ressources/Year2024/day17/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<Pos> stars;
    int line = 0;
    while(getline(f, s)) {
        for (int i = 0; i < s.size(); i++) if (s[i] == '*') stars.emplace_back(i, line);
        line++;
    }

    vector<Edge> constellation = kruskal(stars);

    cout << constellationSize(constellation) << endl;
    return 0;
}