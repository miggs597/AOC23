#include <iostream>
#include <sstream>
#include <string>

using namespace std;

auto parse(const string &line) -> int {
    int red { 12 };
    int green { 13 };
    int blue { 14 };
    
    stringstream ss { line };
    string game, game_id, color;
    int count;

    ss >> game >> game_id;
    while (ss >> count) {
        ss >> color;

        switch (color[0]) {
            case 'r':
                red -= count;
                break;
            case 'g':
                green -= count;
                break;
            case 'b':
                blue -= count;
                break;
            default:
                cout << "nani\n";
                break;
        }

        
        if (red < 0 || green < 0 || blue < 0) {
            return 0;
        }

        if (color.ends_with(';')) {
            red = 12;
            green = 13;
            blue = 14;
        }
    }

    game_id.pop_back();
    return stoi(game_id);
}



int main() {
    int sum = 0;
    for (string line; getline(cin, line);) {
        sum += parse(line);
    }

    cout << sum << '\n';

    return 0;
}
