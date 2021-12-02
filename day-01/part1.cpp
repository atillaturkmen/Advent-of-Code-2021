#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll ans = 0;
    ll before, after;
    cin >> before;
    while (cin >> after) {
        if (after > before) {
            ans++;
        }
        before = after;
    }
    cout << ans;
    return 0;
}