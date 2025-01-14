#include "utils.h"

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

bool checkIfHitMeteor(Pos start, const int& power, Pos meteor) {
    for (int j = 0; j < power; j++) {
        start.x++;
        start.y++;
        meteor.x--;
        meteor.y--;
        if (start == meteor) return true;
    }
    for (int j = 0; j < power; j++) {
        start.x++;
        meteor.x--;
        meteor.y--;
        if (start == meteor) return true;
    }
    while (start.x <= meteor.x && start.y >= 0) {
        start.x++;
        start.y--;
        meteor.x--;
        meteor.y--;
        if (start == meteor) return true;
    }
    return false;
}
