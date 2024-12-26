#include "utils.h"

int processChar(const char& c) {
    if (c == 'B') return 1;
    if (c == 'C') return 3;
    if (c == 'D') return 5;
    return 0;
}