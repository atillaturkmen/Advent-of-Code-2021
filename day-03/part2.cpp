#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

char findMostCommon(vector<string>& in, int digit) {
    ll sum = 0;
    for (string s : in) {
        if (s[digit] == '1') {
            sum++;
        } else {
            sum--;
        }
    }
    if (sum < 0) {
        return '0';
    } else {
        return '1';
    }
}

char findLeastCommon(vector<string>& in, int digit) {
    if (findMostCommon(in, digit) == '1') {
        return '0';
    } else {
        return '1';
    }
}

string findOxygen(vector<string> in, int digit) {
    while (in.size() != 1) {
        char mostCommon = findMostCommon(in, digit);
        vector<string> out;
        for (string s : in) {
            if (s[digit] == mostCommon) {
                out.push_back(s);
            }
        }
        in = out;
        digit++;
    }
    return in[0];
}

string findCO2(vector<string>& in, int digit) {
    while (in.size() != 1) {
        char leastCommon = findLeastCommon(in, digit);
        vector<string> out;
        for (string s : in) {
            if (s[digit] == leastCommon) {
                out.push_back(s);
            }
        }
        in = out;
        digit++;
    }
    return in[0];
}

ll binaryToDecimal(string& binary) {
    ll decimal = 0;
    ll size = binary.size();
    for (int i = 0; i < size; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (size - i - 1);
        }
    }
    return decimal;
}

int main() {
    vector<string> sum;
    string in;
    while (cin >> in) {
        sum.push_back(in);
    }
    string oxygen = findOxygen(sum, 0);
    string co2 = findCO2(sum, 0);
    ll oxygenDecimal = binaryToDecimal(oxygen);
    ll co2Decimal = binaryToDecimal(co2);
    cout << oxygenDecimal * co2Decimal << endl;
    return 0;
}