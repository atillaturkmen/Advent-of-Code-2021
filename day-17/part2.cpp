#include <iostream>
#include <regex>

using namespace std;
typedef long long ll;

bool hit(int x1, int x2, int y1, int y2, int xi, int yi);

int main() {
    string str;
    getline(cin, str);
    regex r(R"(target area: x=(-?\d*)..(-?\d*), y=(-?\d*)..(-?\d*))");
    smatch m;
    int x1, x2, y1, y2;
    if (regex_search(str, m, r)) {
        x1 = stoi(m[1]);
        x2 = stoi(m[2]);
        y1 = stoi(m[3]);
        y2 = stoi(m[4]);
    } else {
        cout << "wrong input sequence";
        return 1;
    }
    ll ans = 0;
    for (int xi = 0; xi <= 1000; xi++) {
        for (int yi = -1000; yi <= 1000; yi++) {
            if (hit(x1, x2, y1, y2, xi, yi))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

bool hit(int x1, int x2, int y1, int y2, int xi, int yi) {
    int locx = 0, locy = 0;
    while (locx <= x2 && locy >= y1) {
        if (locx <= x2 && locx >= x1 && locy >= y1 && locy <= y2) {
            return true;
        }
        locx += xi;
        locy += yi;
        yi -= 1;
        if (xi < 0)
            xi++;
        if (xi > 0)
            xi--;
    }
    return false;
}