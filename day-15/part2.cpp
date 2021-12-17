#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    vector<vector<int>> smallGraph;
    string line;
    while (getline(cin, line)) {
        vector<int> lineNum;
        for (char c : line)
            lineNum.push_back(c - '0');
        smallGraph.push_back(lineNum);
    }
    ll size = smallGraph.size();
    vector<vector<ll>> graph(size * 5, vector<ll>(size * 5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ll t = size * i;
                ll onePlus = smallGraph[j][k] + i;
                graph[j + t][k] = onePlus % 10;
                if (onePlus >= 10)
                    graph[j + t][k]++;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size * 5; j++) {
            for (int k = 0; k < size; k++) {
                ll t = size * i;
                ll onePlus = graph[j][k] + i;
                graph[j][k + t] = onePlus % 10;
                if (onePlus >= 10)
                    graph[j][k + t]++;
            }
        }
    }
    vector<vector<ll>> dist(graph.size(), vector<ll>(graph[0].size(), LLONG_MAX));
    dist[0][0] = 0;
    set<pair<ll, pair<ll, ll>>> sp; // {shortest path distance, {y, x}}
    sp.insert({0, {0, 0}});
    while (!sp.empty()) {
        pair<ll, pair<ll, ll>> cur = *(sp.begin());
        sp.erase(sp.begin());
        ll y = cur.second.first;
        ll x = cur.second.second;
        for (ll j = y - 1; j <= y + 1; j++) {
            for (ll k = x - 1; k <= x + 1; k++) {
                if (j != y && k != x) continue;
                if (j == y && k == x) continue;
                if (j < 0 || j >= graph.size()) continue;
                if (k < 0 || k >= graph.size()) continue;
                // adjacent nodes
                int weight = graph[j][k];
                if (dist[j][k] > dist[y][x] + weight) {
                    if (dist[j][k] != LLONG_MAX)
                        sp.erase(sp.find({dist[j][k], {j, k}}));
                    dist[j][k] = dist[y][x] + weight;
                    sp.insert({dist[j][k], {j, k}});
                }
            }
        }
    }
    cout << dist[graph.size() - 1][graph[0].size() - 1] << endl;
    return 0;
}