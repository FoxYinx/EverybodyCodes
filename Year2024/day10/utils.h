#ifndef UTILS_H
#define UTILS_H
#include <array>
#include <vector>
#define SIZE 8
#define BIGSIZE 14

using namespace std;

char findLetter(const array<array<char, SIZE>, SIZE>& map, const int& y, const int& x);
char findLetterVector(const vector<vector<char>>& map, const int& y, const int& x, const int& cornerY, const int& cornerX);
bool trytoSolve(vector<vector<char>>& map, const int& y, const int& x);
bool tryToComplete(vector<vector<char>>& wall, const int& y, const int& x);

#endif /*UTILS_H*/
