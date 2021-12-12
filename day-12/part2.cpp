#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

vector<unordered_set<ll>> graph;
unordered_set<ll> canVisitMore;
ll startCode, endCode;

void assignCode(const string &s, ll &lastCode, unordered_map<string, ll> &code);

void backTrack(ll &ans, vector<ll> &visited, ll cur);

int main() {
    string first, second;
    ll lastCode = 0;
    unordered_map<string, ll> code;
    while (getline(cin, first, '-')) {
        cin >> second;
        if (first[0] == '\n') {
            first = first.substr(1, first.size() - 1);
        }
        assignCode(first, lastCode, code);
        assignCode(second, lastCode, code);
        ll firstCode = code[first];
        ll secondCode = code[second];
        graph[firstCode].insert(secondCode);
        graph[secondCode].insert(firstCode);
    }
    vector<ll> visited(lastCode, 0);
    ll ans = 0;
    backTrack(ans, visited, startCode);
    cout << ans << endl;
    return 0;
}

void backTrack(ll &ans, vector<ll> &visited, ll cur) {
    visited[cur]++;
    if (cur == endCode)
        ans++;
    else {
        for (ll adj : graph[cur]) {
            if (adj == startCode) continue;
            if (canVisitMore.find(adj) == canVisitMore.end() && visited[adj] > 1) continue;
            backTrack(ans, visited, adj);
        }
    }
    visited[cur]--;
}

void assignCode(const string &s, ll &lastCode, unordered_map<string, ll> &code) {
    if (code.find(s) == code.end()) {
        if (s == "start")
            startCode = lastCode;
        else if (s == "end")
            endCode = lastCode;
        bool allUpper = true;
        for (char c : s) {
            if (!isupper(c)) {
                allUpper = false;
                break;
            }
        }
        if (allUpper)
            canVisitMore.insert(lastCode);
        code.insert(make_pair(s, lastCode++));
        graph.emplace_back();
    }
}