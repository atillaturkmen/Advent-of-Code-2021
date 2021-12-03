#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    string cur;
    cin >> cur;
    ll length = cur.length();
    ll sum[length] = {0};
    do {
        for (int i = 0; i < length; i++) {
            if (cur[i] == '1') {
                sum[i]++;
            } else {
                sum[i]--;
            }
        }
    } while (cin >> cur);
    ll gamma = 0;
    ll epsilon = 0;
    for (ll i = 0; i < length; i++) {
        if (sum[i] > 0) {
            gamma += 1 << (length - i - 1); // += pow(2, (length - i - 1))
        } else {
            epsilon += 1 << (length - i - 1); // += pow(2, (length - i - 1))
        }
    }
    cout << gamma * epsilon;
    return 0;
}