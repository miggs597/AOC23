#include <iostream>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <string>
#include <cctype>
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
    auto range = ranges::subrange(istream_iterator<string> { cin }, istream_iterator<string> { })
        | ranges::views::transform(parse_calibration);

    cout << accumulate(range.begin(), range.end(), 0) << "\n"; 
    return 0;
}
