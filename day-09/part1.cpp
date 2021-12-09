#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    string nextLine;
    vector<vector<int>> heights;
    while (getline(cin, nextLine)) {
        vector<int> lineList(nextLine.size());
        for (int i = 0; i < nextLine.size(); i++) {
            lineList[i] = nextLine[i] - '0'; // subtract ascii values to convert from char to int
        }
        heights.push_back(lineList);
    }
    ll h = heights.size();
    ll w = heights[0].size();
    ll ans = 0;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            int t = (i == 0) ? 10 : heights[i - 1][j];
            int l = (j == 0) ? 10 : heights[i][j - 1];
            int b = (i == h - 1) ? 10 : heights[i + 1][j];
            int r = (j == w - 1) ? 10 : heights[i][j + 1];
            int cur = heights[i][j];
            bool lowPoint = true;
            for (int side : {t, l, b, r}) {
                if (cur >= side) {
                    lowPoint = false;
                    break;
                }
            }
            if (lowPoint) {
                ans += cur + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}