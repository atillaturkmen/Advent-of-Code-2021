#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll ans = 0;
    ll first, second, third, next;
    cin >> first >> second >> third;
    while (cin >> next) {
        ll sum1 = first + second + third;
        ll sum2 = second + third + next;
        if (sum2 > sum1) {
            ans++;
        }
        first = second;
        second = third;
        third = next;
    }
    cout << ans;
    return 0;
}