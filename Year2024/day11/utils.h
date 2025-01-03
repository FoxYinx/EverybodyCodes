#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, uint64_t> evol(const map<string, uint64_t>& termites, const map<string, vector<string>>& evolution);
uint64_t runFullEvolution(const int& iter, const map<string, vector<string>>& evolution, const string& starting);

#endif
