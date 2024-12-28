#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <regex>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    string name;
    int distance;
    string path;
};

void bfsPart2(map<string, vector<string>>& tree, vector<Node>& distances);

int year2024_day6_puzzle2() {
    ifstream f("ressources/Year2024/day6/part2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\w+):)");
    const regex regexp2(R"((\w+|@),)");
    smatch sm;
    map<string, vector<string>> tree;
    while (getline(f, s)) {
        s.insert(s.end(), ',');
        string key;
        if (regex_search(s, sm, regexp)) {
            key = sm[1];
        }
        vector<string> values;
        while (regex_search(s, sm, regexp2)) {
            values.push_back(sm[1]);
            s = sm.suffix();
        }
        tree[key] = values;
    }

    vector<Node> distances;
    bfsPart2(tree, distances);

    ranges::sort(distances, [](const Node& a, const Node& b) {
            return a.distance < b.distance;
        });

    for (const Node& node : distances) {
        cout << node.distance << " " << node.path << endl;
    }

    return 0;
}

void bfsPart2(map<string, vector<string>>& tree, vector<Node>& distances) {
    queue<Node> file;
    file.emplace("RR", 0, "R");

    while (!file.empty()) {
        string name = file.front().name;
        int distance = file.front().distance;
        string path = file.front().path;
        file.pop();

        if (name == "@") {
            distances.emplace_back(name, distance, path);
            continue;
        }

        for (const auto& v : tree[name]) {
            file.emplace(v, distance + 1, path + v [0]);
        }
    }
}