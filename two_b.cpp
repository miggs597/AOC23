#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ranges>

using namespace std;

auto parse(const string &line) -> int {
    int red { 1 };
    int green { 1 };
    int blue { 1 };
    
    stringstream ss { line };
    string game, game_id, color;
    int count;

    ss >> game >> game_id;
    while (ss >> count) {
        ss >> color;

        switch (color[0]) {
            case 'r':
                red = ranges::max(red, count);
                break;
            case 'g':
                green = ranges::max(green, count);
                break;
            case 'b':
                blue = ranges::max(blue, count);
                break;
            default:
                cout << "nani\n";
                break;
        }
    }

    return red * green * blue;
}



int main() {
    int sum = 0;
    for (string line; getline(cin, line);) {
        sum += parse(line);
    }

    cout << sum << '\n';

    return 0;
}
