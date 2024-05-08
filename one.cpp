#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>


using namespace std;

auto parse_calibration(const  string &line) -> int {
    auto pred = [](const char & c) { return isdigit(c); };

    string value { 2 };
    value[0] = *ranges::find_if(line, pred);
    value[1] = *ranges::find_if(line | ranges::views::reverse, pred);
    
    return stoi(value);
}

int main() {
    auto range = ranges::views::istream<string>(cin)
        | ranges::views::transform(parse_calibration);

    cout << ranges::fold_left(range, 0, std::plus{})<< "\n"; 
    return 0;
}
