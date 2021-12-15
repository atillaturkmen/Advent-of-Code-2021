#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    string init;
    cin >> init;
    string nextLine;
    unordered_map<string, char> insertion;
    unordered_map<string, ll> nofPair;
    while (getline(cin, nextLine)) {
        if (nextLine.empty()) continue;
        string pair = nextLine.substr(0, 2);
        insertion.insert({pair, nextLine[nextLine.size() - 1]});
        nofPair.insert({pair, 0});
    }
    string left = init.substr(0, 2);
    string right = init.substr(init.size() - 2, init.size());
    for (int i = 0; i < init.size() - 1; i++) {
        nofPair[init.substr(i, 2)]++;
    }
    const int STEPS = 10;
    for (int i = 0; i < STEPS; i++) {
        unordered_map<string, ll> temp;
        temp = nofPair; // deep copy
        for (const auto &pair : nofPair) {
            if (pair.second == 0) continue;
            temp[pair.first] -= pair.second;
            char middleChar = insertion[pair.first];
            string leftPair = pair.first[0] + string(1, middleChar);
            string rightPair = string(1, middleChar) + pair.first[1];
            if (pair.first == left)
                left = leftPair;
            if (pair.first == right)
                right = rightPair;
            temp[leftPair] += pair.second;
            temp[rightPair] += pair.second;
        }
        nofPair = temp;
    }
    unordered_map<char, ll> occurrence;
    occurrence[left[0]]++;
    occurrence[right[1]]++;
    for (const auto &i : nofPair) {
        occurrence[i.first[0]] += i.second;
        occurrence[i.first[1]] += i.second;
    }
    for (auto &i : occurrence) {
        i.second /= 2;
    }
    ll minn = occurrence.begin()->second;
    ll maxx = occurrence.begin()->second;
    for (const auto &i : occurrence) {
        minn = min(i.second, minn);
        maxx = max(i.second, maxx);
    }
    cout << maxx - minn << endl;
    return 0;
}