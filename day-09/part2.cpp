#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<pair<ll, ll>> lowPoints;
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
                lowPoints.emplace_back(i, j);
            }
        }
    }
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<ll> basinSize;
    for (auto low : lowPoints) {
        ll size = 0;
        visited[low.first][low.second] = true;
        queue<pair<ll, ll>> bfs;
        bfs.push(low);
        while (!bfs.empty()) {
            ll i = bfs.front().first;
            ll j = bfs.front().second;
            bfs.pop();
            size++;
            int cur = heights[i][j];
            vector<pair<pair<ll, ll>, int>> sides; // { {y, x}, height }
            int t = (i == 0) ? 9 : heights[i - 1][j];
            sides.push_back({{i - 1, j}, t});
            int l = (j == 0) ? 9 : heights[i][j - 1];
            sides.push_back({{i, j - 1}, l});
            int b = (i == h - 1) ? 9 : heights[i + 1][j];
            sides.push_back({{i + 1, j}, b});
            int r = (j == w - 1) ? 9 : heights[i][j + 1];
            sides.push_back({{i, j + 1}, r});
            for (auto side : sides) {
                int height = side.second;
                ll y = side.first.first;
                ll x = side.first.second;
                if (height > cur && height != 9 && !visited[y][x]) {
                    visited[y][x] = true;
                    bfs.push({y, x});
                }
            }
        }
        basinSize.push_back(size);
    }
    sort(basinSize.begin(), basinSize.end(), greater<int>());
    ll ans = 1;
    for (int i = 0; i < 3; i++) {
        ans *= basinSize[i];
    }
    cout << ans << endl;
    return 0;
}