#include <iostream>
#include <stack>
#include <unordered_map>

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
            {')', 3},
            {']', 57},
            {'}', 1197},
            {'>', 25137},
    };
    string next;
    ll ans = 0;
    while (getline(cin, next)) {
        stack<char> s;
        for (char c : next) {
            if (c == '(' || c == '[' || c == '{' || c == '<')
                s.push(c);
            else if (s.empty())
                ans += charScore[c];
            else {
                char last = s.top();
                s.pop();
                if (pairs[c] != last) {
                    ans += charScore[c];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}