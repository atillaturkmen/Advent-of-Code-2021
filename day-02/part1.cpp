#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll position = 0;
    ll depth = 0;
    string in;
    ll inNum;
    while (cin >> in) {
        cin >> inNum;
        if (in == "forward") {
            position += inNum;
        }
        else if (in == "up") {
            depth -= inNum;
        }
        else {
            depth += inNum;
        }
    }
    cout << position * depth;
    return 0;
}