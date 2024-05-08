#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

using namespace std;

const unordered_map<string, char> conversion {
    { "one", '1' },
    { "two", '2' },
    { "three", '3' },
    { "four", '4' },
    { "five", '5' },
    { "six", '6' },
    { "seven", '7' },
    { "eight", '8' },
    { "nine" , '9' }
};

auto parse_calibration(const string &line) -> int {
    auto l { line };
    ranges::for_each(conversion, [&](const pair<string, char> &p) {
        for (auto i = l.find(p.first); i != l.npos; i = l.find(p.first)) {
            l[i + 1] = p.second;
        }
    });

    auto pred = [](const char &c) { return isdigit(c); };

    string value { 2 };
    value[0] = *ranges::find_if(l, pred);
    value[1] = *ranges::find_if(l | ranges::views::reverse, pred);
    
    return stoi(value); 
}

int main() {
    auto range = ranges::views::istream<string>(cin)
        | ranges::views::transform(parse_calibration);

    cout << ranges::fold_left(range, 0, plus{}) << "\n"; 
    return 0;
}
