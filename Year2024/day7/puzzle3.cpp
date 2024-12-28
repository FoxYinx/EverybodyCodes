#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include <queue>
#include <array>

#define LAPS 11

using namespace std;

struct Pos {
    int x;
    int y;
};

constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

string getTrack(const string& trackFile);
uint64_t getScore(const string& track, const vector<string>& device);
vector<vector<string>> getAllStrategies();

int year2024_day7_puzzle3() {
    ifstream f("ressources/Year2024/day7/part3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\w+):)");
    const regex regexp2(R"((\+|\-|\=),)");
    smatch sm;
    map<string, vector<string>> devices;
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
        devices[key] = values;
    }

    string track = getTrack("ressources/Year2024/day7/track.txt");

    uint64_t enemy = getScore(track, devices["A"]);
    uint64_t ways = 0;
    for (const vector<string>& strategy : getAllStrategies()) {
        if (getScore(track, strategy) > enemy) ways++;
    }

    cout << ways << endl;
    return 0;
}

vector<vector<string>> getAllStrategies() {
    vector<vector<string>> strategies;
    string s = "+++++---===";
    sort(s.begin(), s.end());
    do {
        vector<string> temp;
        for (char & i : s) {
            temp.emplace_back(1, i);
        }
        strategies.push_back(temp);
    } while (std::next_permutation(s.begin(), s.end()));
    return strategies;
}

uint64_t getScore(const string& track, const vector<string>& device) {
    uint64_t result = 0;
    uint64_t temp = 10;
    for (int i = 0; i < track.size() * LAPS; i++) {
        const string trackOp(1, track[(i + 1) % track.size()]);
        const string& racerOp = device.at(i % device.size());
        if (trackOp == "S" || trackOp == "=") {
            if (racerOp == "+") {
                temp++;
            } else if (racerOp == "-") {
                if (temp > 0) temp--;
            }
        } else if (trackOp == "+") {
            temp++;
        } else {
            if (temp > 0) temp--;
        }
        result += temp;
    }
    return result;
}

string getTrack(const string& trackFile) {
    //fixme: works only with the debugger on
    ifstream fi(trackFile);
    string temp;
    vector<vector<char>> trackChar;
    while (getline(fi, temp)) {
        vector<char> tempVec;
        for (const char& c : temp) tempVec.push_back(c);
        trackChar.push_back(tempVec);
    }
    vector trackBool(trackChar.size(), vector<bool>(trackChar[0].size()));
    trackBool[0][0] = true;
    trackBool[0][1] = true;
    queue<Pos> file;
    file.emplace(1, 0);

    string track = "S";

    while (!file.empty()) {
        int x = file.front().x;
        int y = file.front().y;
        file.pop();

        track += trackChar[y][x];

        for (const auto&[dx, dy] : directions) {
            int nx = x + dx;
            if (int ny = y + dy; nx >= 0 && ny >= 0 && nx < trackChar[0].size() && ny < trackChar.size()) {
                if (!trackBool[ny][nx] && (trackChar[ny][nx] == '+' || trackChar[ny][nx] == '-' || trackChar[ny][nx] == '=' || trackChar[ny][nx] == 'S')) {
                    file.emplace(nx, ny);
                    trackBool[ny][nx] = true;
                }
            }
        }
    }

    return track;
}