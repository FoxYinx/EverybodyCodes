#include <fstream>
#include <functional>
#include <iostream>
#include <map>

using namespace std;

// Function declarations
int year2024_day1_puzzle1();
int year2024_day1_puzzle2();
int year2024_day1_puzzle3();
int year2024_day2_puzzle1();
int year2024_day2_puzzle2();
int year2024_day2_puzzle3();
int year2024_day3_puzzle1();
int year2024_day3_puzzle2();
int year2024_day3_puzzle3();
int year2024_day4_puzzle1();
int year2024_day4_puzzle2();
int year2024_day4_puzzle3();
int year2024_day5_puzzle1();
int year2024_day5_puzzle2();
int year2024_day5_puzzle3();

// Function registry
map<string, function<int()> > functions = {
    {"2024-1-1", year2024_day1_puzzle1},
    {"2024-1-2", year2024_day1_puzzle2},
    {"2024-1-3", year2024_day1_puzzle3},
    {"2024-2-1", year2024_day2_puzzle1},
    {"2024-2-2", year2024_day2_puzzle2},
    {"2024-2-3", year2024_day2_puzzle3},
    {"2024-3-1", year2024_day3_puzzle1},
    {"2024-3-2", year2024_day3_puzzle2},
    {"2024-3-3", year2024_day3_puzzle3},
    {"2024-4-1", year2024_day4_puzzle1},
    {"2024-4-2", year2024_day4_puzzle2},
    {"2024-4-3", year2024_day4_puzzle3},
    {"2024-5-1", year2024_day5_puzzle1},
    {"2024-5-2", year2024_day5_puzzle2},
    {"2024-5-3", year2024_day5_puzzle3},
};

int main() {
    int year, day, puzzle;
    cout << "Enter which year: ";
    cin >> year;
    cout << "Enter which day: ";
    cin >> day;
    cout << "Enter which part (1, 2 or 3): ";
    cin >> puzzle;
    if (const string key = to_string(year) + "-" + to_string(day) + "-" + to_string(puzzle); functions.contains(key)) {
        std::cout << "Running Year " << year << " Day " << day << " Part " << puzzle << "...\n";
        return functions[key](); // Call the corresponding function
    }
    std::cout << "Invalid day or part. Please check your input.\n";
    return 1;
}
