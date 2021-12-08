#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

set<char> stringToSet(const string &in) {
    set<char> set;
    for (char c : in) {
        set.insert(c);
    }
    return set;
}

int main() {
    string next;
    ll ans = 0;
    set<char> all = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    while (cin >> next) {
        vector<set<char>> fiveChars, sixChars;
        set<char> one, four, seven;
        map<set<char>, int> solution;
        for (int i = 0; i < 10; i++) {
            set<char> chars = stringToSet(next);
            if (next.size() == 2) {
                one = chars;
                solution[one] = 1;
            } else if (next.size() == 4) {
                four = chars;
                solution[four] = 4;
            } else if (next.size() == 3) {
                seven = chars;
                solution[seven] = 7;
            } else if (next.size() == 5) {
                fiveChars.push_back(chars);
            } else if (next.size() == 6) {
                sixChars.push_back(chars);
            } else {
                solution[chars] = 8;
            }
            cin >> next;
        }

        set<char> sixCharIntersection, sixAndFiveCharIntersection, missingInSixChars, temp, temp2;
        // intersect of six chars
        set_intersection(sixChars[0].begin(), sixChars[0].end(), sixChars[1].begin(), sixChars[1].end(),
                         inserter(temp, temp.begin()));
        set_intersection(sixChars[2].begin(), sixChars[2].end(), temp.begin(), temp.end(),
                         inserter(sixCharIntersection, sixCharIntersection.begin()));
        temp.clear();
        // intersect of five and six chars
        set_intersection(fiveChars[0].begin(), fiveChars[0].end(), sixCharIntersection.begin(),
                         sixCharIntersection.end(),
                         inserter(temp, temp.begin()));
        set_intersection(fiveChars[1].begin(), fiveChars[1].end(), temp.begin(), temp.end(),
                         inserter(temp2, temp2.begin()));
        set_intersection(fiveChars[2].begin(), fiveChars[2].end(), temp2.begin(), temp2.end(),
                         inserter(sixAndFiveCharIntersection, sixAndFiveCharIntersection.begin()));
        temp.clear();
        temp2.clear();
        // chars that are missing from six char digits
        for (const set<char> &digit : sixChars) {
            set_difference(all.begin(), all.end(), digit.begin(), digit.end(), inserter(temp, temp.begin()));
            missingInSixChars.insert(*temp.begin());
            temp.clear();
        }
        set<char> found;
        // find char at the top
        set_difference(seven.begin(), seven.end(), one.begin(), one.end(), inserter(temp, temp.begin()));
        char up = *temp.begin();
        found.insert(up);
        temp.clear();
        // find char at the bottom
        char down;
        for (char c : sixAndFiveCharIntersection) {
            if (c != up) {
                down = c;
            }
        }
        found.insert(down);
        // find middle char
        set_difference(four.begin(), four.end(), one.begin(), one.end(), inserter(temp, temp.begin()));
        set_intersection(temp.begin(), temp.end(), missingInSixChars.begin(), missingInSixChars.end(),
                         inserter(temp2, temp2.begin()));
        char middle = *temp2.begin();
        found.insert(middle);
        temp2.clear();
        // find top left
        char topLeft;
        for (char c : temp) {
            if (c != middle) {
                topLeft = c;
            }
        }
        found.insert(topLeft);
        temp.clear();
        // find top right
        set_intersection(one.begin(), one.end(), missingInSixChars.begin(), missingInSixChars.end(),
                         inserter(temp, temp.begin()));
        char topRight = *temp.begin();
        found.insert(topRight);
        temp.clear();
        // find bottom right
        char bottomRight;
        for (char c : one) {
            if (c != topRight) {
                bottomRight = c;
            }
        }
        found.insert(bottomRight);
        // find bottom left
        set_difference(all.begin(), all.end(), found.begin(), found.end(), inserter(temp, temp.begin()));
        char bottomLeft = *temp.begin();
        temp.clear();

        // map strings to digits
        for (int i = 0; i < 3; i++) {
            set<char> &digit = sixChars[i];
            set_difference(all.begin(), all.end(), digit.begin(), digit.end(), inserter(temp, temp.begin()));
            if (*temp.begin() == middle) {
                solution[digit] = 0;
            } else if (*temp.begin() == topRight) {
                solution[digit] = 6;
            } else if (*temp.begin() == bottomLeft) {
                solution[digit] = 9;
            } else {
                return 1;
            }
            temp.clear();
        }
        set<char> missingInTwo = {topLeft, bottomRight};
        set<char> missingInThree = {topLeft, bottomLeft};
        set<char> missingInFive = {topRight, bottomLeft};
        for (int i = 0; i < 3; i++) {
            set<char> &digit = fiveChars[i];
            set_difference(all.begin(), all.end(), digit.begin(), digit.end(), inserter(temp, temp.begin()));
            if (temp == missingInTwo) {
                solution[digit] = 2;
            } else if (temp == missingInThree) {
                solution[digit] = 3;
            } else if (temp == missingInFive) {
                solution[digit] = 5;
            } else {
                return 1;
            }
            temp.clear();
        }

        for (int i = 3; i >= 0; i--) {
            cin >> next;
            int digit = solution[stringToSet(next)];
            ans += digit * pow(10, i);
        }
    }
    cout << ans << endl;
    return 0;
}