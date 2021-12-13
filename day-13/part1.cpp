#include <iostream>
#include <unordered_set>

using namespace std;
typedef long long ll;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};

int main() {
    string nextLine;
    unordered_set<pair<int, int>, pair_hash> dots;
    char foldAxis;
    int foldCoordinate;
    while (getline(cin, nextLine)) {
        int delim = nextLine.find(',');
        if (delim != -1) {
            int x = stoi(nextLine.substr(0, delim));
            int y = stoi(nextLine.substr(delim + 1, nextLine.size()));
            dots.insert({x, y});
        } else {
            getline(cin, nextLine);
            int eq = nextLine.find('=');
            foldAxis = nextLine[eq - 1];
            foldCoordinate = stoi(nextLine.substr(eq + 1, nextLine.size()));
            break;
        }
    }
    double ans = dots.size();
    if (foldAxis == 'y') {
        for (pair<int, int> dot : dots) {
            if (dot.second == foldCoordinate)
                ans--;
            if (dots.find({dot.first, abs(2 * foldCoordinate - dot.second)}) != dots.end())
                ans -= 1. / 2;
        }
    } else {
        for (pair<int, int> dot : dots) {
            if (dot.first == foldCoordinate)
                ans--;
            if (dots.find({abs(2 * foldCoordinate - dot.first), dot.second}) != dots.end())
                ans -= 1. / 2;
        }
    }
    cout << ans << endl;
    return 0;
}