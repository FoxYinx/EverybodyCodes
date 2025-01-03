#include <ranges>
#include "utils.h"

map<string, uint64_t> evol(const map<string, uint64_t>& termites, const map<string, vector<string>>& evolution) {
    map<string, uint64_t> output;
    for (const string &key: termites | views::keys) {
        for (const string& toEvolve : evolution.at(key)) {
            output[toEvolve] += termites.at(key);
        }
    }
    return output;
}

uint64_t runFullEvolution(const int& iter, const map<string, vector<string>>& evolution, const string& starting) {
    map<string, uint64_t> termites;
    termites[starting] = 1;

    for (int i = 0; i < iter; i++) {
        termites = evol(termites, evolution);
    }

    uint64_t population = 0;
    for (const uint64_t &value: termites | views::values) {
        population += value;
    }
    return population;
}