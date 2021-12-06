#include <iostream>

using namespace std;
typedef long long ll;

const int days = 256;
ll dp[days + 1];

/*
 * number of lantern fish after x days from one fish with timer 0 = f(x) = f(x - 9) + f(x - 7)
 * f(0) = 1, f(1) = 2 ... f(7) = 2, f(8) = 3
 */
ll nofFish(ll n) {
    if (dp[n] != 0) return dp[n];
    if (n == 0) return 1;
    if (n < 8) return 2;
    if (n == 8) return 3;
    ll result = nofFish(n - 9) + nofFish(n - 7);
    dp[n] = result;
    return result;
}

int main() {
    fill(dp, dp + days + 1, 0);
    string next;
    ll ans = 0;
    while (getline(cin, next, ',')) {
        int num = stoi(next);
        ans += nofFish(days - num);
    }
    cout << ans << endl;
    return 0;
}