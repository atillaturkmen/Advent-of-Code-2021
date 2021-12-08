#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    string next;
    ll ans = 0;
    while (cin >> next) {
        if (next == "|") {
            for (int i = 0; i < 4; i++) {
                cin >> next;
                if (next.size() == 2 ||
                    next.size() == 4 ||
                    next.size() == 3 ||
                    next.size() == 7) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}