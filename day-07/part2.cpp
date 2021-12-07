#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll totalFuel(vector<ll> &in, ll dest) {
    ll fuel = 0;
    for (ll i : in) {
        ll dist = abs(i - dest);
        fuel += dist * (dist + 1) / 2;
    }
    return fuel;
}

int main() {
    vector<ll> input;
    string next;
    while (getline(cin, next, ',')) {
        input.push_back(stoi(next));
    }
    sort(input.begin(), input.end());
    ll median = input[input.size() / 2];
    while (true) {
        ll before = totalFuel(input, median - 1);
        ll current = totalFuel(input, median);
        ll after = totalFuel(input, median + 1);
        if (current > after && before > current) {
            median++;
        } else if (current < after && before < current) {
            median--;
        } else {
            cout << current << endl;
            return 0;
        }
    }
}