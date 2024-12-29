#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

using namespace std;

int findMin(int input, const vector<int>& stamps, map<int, int>& memory);

int year2024_day9_puzzle2() {
    ifstream f("ressources/Year2024/day9/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int total = 0;
    const vector stamps = {30, 25, 24, 20, 16, 15, 10, 5, 3, 1};
    while (getline(f, s)) {
        const int input = stoi(s);
        map<int, int> memory;
        total += findMin(input, stamps, memory);
    }

    cout << total << endl;
    return 0;
}

int findMin(const int input, const vector<int>& stamps, map<int, int>& memory) {
    if (input == 0) return 0;
    if (input < 0) return numeric_limits<int>::max() - 1;
    if (memory.contains(input)) return memory[input];
    int best = numeric_limits<int>::max() - 1;
    for (const int& stamp : stamps) {
        best = min(findMin(input - stamp, stamps, memory) + 1, best);
    }
    memory[input] = best;
    return best;
}