#include <limits>
#include "utils.h"

int findMin(const int input, const vector<int>& stamps, map<int, int>& memory) {
    if (input == 0) return 0;
    if (input < 0) return numeric_limits<int>::max() - 1;
    if (memory.contains(input)) return memory[input];
    int best = numeric_limits<int>::max() - 1;
    for (const int& stamp : stamps) {
        best = min(findMin(input - stamp, stamps, memory) + 1, best);
    }
    memory[input] = best;
    return best;
}