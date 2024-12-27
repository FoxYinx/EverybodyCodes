#include <algorithm>
#include "utils.h"

int flattenNails(vector<int>& nails) {
    ranges::sort(nails);

    int strikes = 0;
    for (int i = 1; i < nails.size(); i++) {
        strikes += nails[i] - nails[0];
    }
    return strikes;
}

int flattenNailsMiddle(vector<int>& nails) {
    ranges::sort(nails);

    int strikes = 0;
    const unsigned long long middle = (nails.size() - 1) / 2;
    for (int i = 0; i < middle; i++) {
        strikes += nails[middle] - nails[i];
    }
    for (unsigned long long i = middle + 1; i < nails.size(); i++) {
        strikes += nails[i] - nails[middle];
    }
    return strikes;
}

