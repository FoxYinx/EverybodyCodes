#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> evol(const map<string, int>& termites, const map<string, vector<string>>& evolution);
int runFullEvolution(const int& iter, const map<string, vector<string>>& evolution, const string& starting);

#endif
