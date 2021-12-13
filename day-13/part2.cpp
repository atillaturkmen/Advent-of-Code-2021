#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};

unordered_set<pair<int, int>, pair_hash>
fold(char axis, int coordinate, unordered_set<pair<int, int>, pair_hash> &dots);

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
            if (nextLine.empty()) continue;
            int eq = nextLine.find('=');
            foldAxis = nextLine[eq - 1];
            foldCoordinate = stoi(nextLine.substr(eq + 1, nextLine.size()));
            dots = fold(foldAxis, foldCoordinate, dots);
        }
    }
    int size = 0;
    for (auto dot : dots) {
        size = dot.first > size ? dot.first : size;
        size = dot.second > size ? dot.second : size;
    }
    size++;
    vector<vector<char>> paper(size, vector<char>(size, '.'));
    for (auto dot : dots) {
        paper[dot.second][dot.first] = '#';
    }
    for (const auto &line : paper) {
        for (char c : line)
            cout << c;
        cout << endl;
    }
    return 0;
}

unordered_set<pair<int, int>, pair_hash>
fold(char axis, int coordinate, unordered_set<pair<int, int>, pair_hash> &dots) {
    unordered_set<pair<int, int>, pair_hash> newDots;
    if (axis == 'y') {
        for (auto dot : dots) {
            if (dot.second < coordinate) {
                newDots.insert(dot);
            } else if (dot.second > coordinate) {
                newDots.insert({dot.first, abs(2 * coordinate - dot.second)});
            }
        }
    } else {
        for (auto dot : dots) {
            if (dot.first < coordinate) {
                newDots.insert(dot);
            } else if (dot.first > coordinate) {
                newDots.insert({abs(2 * coordinate - dot.first), dot.second});
            }
        }
    }
    return newDots;
}