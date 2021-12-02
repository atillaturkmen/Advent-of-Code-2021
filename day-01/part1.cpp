#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll ans = 0;
    ll before;
    ll after;
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