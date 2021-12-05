#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
typedef long long ll;

vector<string> split(string, const string&);

int main() {
    string in;
    cin >> in;
    vector<string> random = split(in, ",");
    int i = 0;
    vector<vector<vector<int>>> boards;
    vector<vector<int>> board;
    int cur;
    // initialize boards as matrix
    while (cin >> cur) {
        if (i == 0) {
            board = vector<vector<int>>(5, vector<int>(5));
        }
        board[i % 5][i / 5] = cur;
        i++;
        if (i == 25) {
            boards.push_back(board);
            i = 0;
        }
    }
    vector<unordered_set<int>> game; // all rows and columns in a set
    for (auto &b : boards) {
        // columns
        for (int j = 0; j < 5; j++) {
            game.emplace_back(b[j].begin(), b[j].end());
        }
        // rows
        for (int j = 0; j < 5; j++) {
            vector<int> row;
            for (int k = 0; k < 5; k++) {
                row.push_back(b[k][j]);
            }
            game.emplace_back(row.begin(), row.end());
        }
    }
    // start bingo
    for (const string& s : random) {
        int next = stoi(s);
        for (ll j = 0; j < game.size(); j++) {
            unordered_set<int>& g = game[j];
            if (g.find(next) != g.end()) { // hit
                g.erase(next);
                if (g.empty()) { // BINGO
                    ll boardNo = j / 10;
                    ll sum = 0;
                    for (ll k = boardNo * 10; k < boardNo*10 + 5; k++) {
                        for (int l : game[k]) {
                            sum += l;
                        }
                    }
                    cout << sum * next << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split(string in, const string& delimiter) {
    ll pos;
    vector<string> split;
    while ((pos = in.find(delimiter)) != string::npos) {
        split.push_back(in.substr(0, pos));
        in.erase(0, pos + delimiter.length());
    }
    split.push_back(in);
    return split;
}