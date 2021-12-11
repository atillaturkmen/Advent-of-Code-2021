#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

vector<vector<int>> fillGrid();

int main() {
    vector<vector<int>> grid = fillGrid();
    ll ans = 0;
    while (true) {
        ans++;
        for (vector<int> &v : grid) {
            for (int &j : v)
                j++;
        }
        queue<pair<ll, ll>> bfs;
        for (ll y = 0; y < grid.size(); y++) {
            for (ll x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] > 9) {
                    bfs.push({y, x});
                    grid[y][x] = 0;
                }
            }
        }
        while (!bfs.empty()) {
            ll y = bfs.front().first;
            ll x = bfs.front().second;
            bfs.pop();
            for (ll j = y - 1; j <= y + 1; j++) {
                for (ll k = x - 1; k <= x + 1; k++) {
                    if (j == y && k == x) continue;
                    if (j < 0 || j >= grid.size()) continue;
                    if (k < 0 || k >= grid.size()) continue;
                    if (grid[j][k] == 0) continue;
                    grid[j][k]++;
                    if (grid[j][k] > 9) {
                        grid[j][k] = 0;
                        bfs.push({j, k});
                    }
                }
            }
        }
        bool allFlashed = true;
        for (auto &v : grid) {
            for (int o : v) {
                if (o != 0) {
                    allFlashed = false;
                }
            }
        }
        if (allFlashed)
            break;
    }
    cout << ans << endl;
    return 0;
}

vector<vector<int>> fillGrid() {
    vector<vector<int>> grid;
    string nextLine;
    while (getline(cin, nextLine)) {
        vector<int> lineList(nextLine.size());
        for (int i = 0; i < nextLine.size(); i++) {
            lineList[i] = nextLine[i] - '0'; // subtract ascii values to convert from char to int
        }
        grid.push_back(lineList);
    }
    return grid;
}