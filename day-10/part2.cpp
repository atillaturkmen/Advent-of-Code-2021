#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'},
            {'>', '<'},
    };
    unordered_map<char, int> charScore = {
            {'(', 1},
            {'[', 2},
            {'{', 3},
            {'<', 4},
    };
    string next;
    vector<ll> scores;
    while (getline(cin, next)) {
        stack<char> s;
        bool isCorrupted = false;
        for (char c : next) {
            if (c == '(' || c == '[' || c == '{' || c == '<')
                s.push(c);
            else if (s.empty()) {
                isCorrupted = true;
                break;
            } else {
                char last = s.top();
                s.pop();
                if (pairs[c] != last) {
                    isCorrupted = true;
                    break;
                }
            }
        }
        if (isCorrupted) continue;
        ll lineScore = 0;
        while (!s.empty()) {
            char opening = s.top();
            s.pop();
            lineScore *= 5;
            lineScore += charScore[opening];
        }
        scores.push_back(lineScore);
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2] << endl;
    return 0;
}