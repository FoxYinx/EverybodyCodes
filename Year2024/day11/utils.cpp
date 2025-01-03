#include <ranges>
#include "utils.h"

map<string, int> evol(const map<string, int>& termites, const map<string, vector<string>>& evolution) {
    map<string, int> output;
    for (const string &key: termites | views::keys) {
        for (const string& toEvolve : evolution.at(key)) {
            output[toEvolve] += termites.at(key);
        }
    }
    return output;
}

int runFullEvolution(const int& iter, const map<string, vector<string>>& evolution, const string& starting) {
    map<string, int> termites;
    termites[starting] = 1;

    for (int i = 0; i < iter; i++) {
        termites = evol(termites, evolution);
    }

    int population = 0;
    for (const int &value: termites | views::values) {
        population += value;
    }
    return population;
}