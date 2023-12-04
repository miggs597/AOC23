#include <iostream>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

auto parse_calibration(const  string &line) -> int {
    auto pred = [](const char & c) { return isdigit(c); };

    string value { 2 };
    value[0] = *ranges::find_if(line, pred);
    value[1] = *ranges::find_if(line | ranges::views::reverse, pred);
    
    return stoi(value);
}

int main() {
    auto range = ranges::subrange(istream_iterator<string> { cin }, istream_iterator<string> { })
        | ranges::views::transform(parse_calibration);

    cout << accumulate(range.begin(), range.end(), 0) << "\n"; 
    return 0;
}
