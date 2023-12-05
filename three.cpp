#include <iostream>
#include <vector>
#include <ranges>
#include <iterator>

using namespace std;

int main() {
    
    auto schematic = vector<string> { istream_iterator<string> { cin }, istream_iterator<string> { } };

    for (const auto & line: schematic) {
        cout << line << '\n'; 
    }
    
    return 0;
}
