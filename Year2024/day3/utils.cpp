#include "utils.h"

void dig(vector<vector<int>>& map, const int& depth) {
    bool flag = false;
    for (int i = 1; i < map.size() - 1; i++) {
        for (int j = 1; j < map[0].size() - 1; j++) {
            if (map[i - 1][j] >= depth - 1 && map[i + 1][j] >= depth - 1 && map[i][j - 1] >= depth - 1 && map[i][j + 1] >= depth - 1 && map[i][j] == depth - 1) {
                map[i][j] = depth;
                flag = true;
            }
        }
    }
    if (flag) dig(map, depth + 1);
}

void digDiag(vector<vector<int>>& map, const int& depth) {
    bool flag = false;
    for (int i = 1; i < map.size() - 1; i++) {
        for (int j = 1; j < map[0].size() - 1; j++) {
            if (map[i - 1][j] >= depth - 1 && map[i + 1][j] >= depth - 1 && map[i][j - 1] >= depth - 1 && map[i][j + 1] >= depth - 1
                && map[i - 1][j - 1] >= depth - 1 && map[i - 1][j + 1] >= depth - 1 && map[i + 1][j - 1] >= depth - 1 && map[i + 1][j + 1] >= depth - 1 && map[i][j] == depth - 1) {
                map[i][j] = depth;
                flag = true;
            }
        }
    }
    if (flag) digDiag(map, depth + 1);
}