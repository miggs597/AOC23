#include <cctype>
#include <iostream>
#include <vector>
#include <ranges>
#include <format>
#include <iterator>

using namespace std;

auto is_touching(const vector<string> & schematic, int x, int y) -> bool {
    int left = x - 1 < 0 ? 0 : x - 1;
    int right = x + 1 > schematic.size() - 1 ? schematic.size() - 1 : x + 1;

    int up = y - 1 < 0 ? 0 : y - 1;
    int down = y + 1 > schematic[0].size() - 1 ? schematic[0].size() - 1 : y + 1;

    auto check = [&](int xx, int yy) { return !isalnum(schematic[xx][yy]) && schematic[xx][yy] != '.'; };

    // cout << format("({}, {}) left: {} right: {} up: {} down: {}\n", x, y, left, right, up, down);
    
    return check(left, up) || check (left, y) || 
           check(left, down) || check(x, up) || 
           check(x, down) || check(right, up) ||
           check(right, y) || check(right, down);
}

int main() {
    auto schematic = vector<string> { istream_iterator<string> { cin }, istream_iterator<string> { } };

    string current_part_number { };
    int line_index = 0;
    int running_total = 0;
    bool touching_symbol = false;

    for (const auto &line: schematic) {
        int char_index = 0;
        
        for (const auto &c: line) {
            if (isdigit(c)) {
                current_part_number += c; 
                
                if (!touching_symbol)                
                    touching_symbol = is_touching(schematic, line_index, char_index);
            }

            if (c == '.' || !isalnum(c)) {
                if (touching_symbol) {
                    cout << format("Part number: {}\n", current_part_number);
                    running_total += stoi(current_part_number);
                    touching_symbol = false;
                }   

                current_part_number = "";                
            }

            char_index++;
        }

        line_index++;
    }

    cout << running_total << '\n';
    return 0;
}
