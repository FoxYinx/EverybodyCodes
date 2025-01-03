#ifndef UTILS_H
#define UTILS_H

using namespace std;

struct Pos {
    int x;
    int y;

    bool operator<(const Pos& other) const;
    bool operator==(const Pos& other) const;
};

bool checkIfHit(Pos start, const int& power, const Pos& end);
bool checkIfHitMeteor(Pos start, const int& power, Pos meteor);

#endif //UTILS_H
