#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    vector<ll> input;
    string next;
    while (getline(cin, next, ',')) {
        input.push_back(stoi(next));
    }
    sort(input.begin(), input.end());
    ll median = input[input.size() / 2];
    ll ans = 0;
    for (ll i : input) {
        ans += abs(i - median);
    }
    cout << ans << endl;
    return 0;
}