#include "utils.h"

bool Pos::operator<(const Pos& other) const {
    if (x != other.x) {
        return x < other.x;
    }
    return y > other.y;
}

bool Pos::operator==(const Pos& other) const {
    return x == other.x && y == other.y;
}

bool checkIfHit(Pos start, const int& power, const Pos& end) {
    for (int j = 0; j < power; j++) {
        start.x++;
        start.y++;
        if (start == end) return true;
    }
    for (int j = 0; j < power; j++) {
        start.x++;
        if (start == end) return true;
    }
    while (start.y != 0) {
        start.x++;
        start.y--;
        if (start == end) return true;
    }
    return false;
}

