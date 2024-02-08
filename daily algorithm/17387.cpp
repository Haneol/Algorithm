#include <bits/stdc++.h>

using namespace std;

/*
    17387 선분 교차 2
*/

int ccw(pair<int,int> x, pair<int,int> y) {
    long long tmp = (long long) x.first * (long long) y.second - (long long) x.second * (long long) y.first;
    if(tmp < 0) return -1;
    else if(tmp > 0) return 1;
    else return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    pair<int,int> a,b,c,d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    pair<int, int> a1 = {c.first-b.first, c.second-b.second};
    pair<int, int> b1 = {d.first-b.first, d.second-b.second};
    pair<int, int> c1 = {b.first-a.first, b.second-a.second};

    pair<int, int> a2 = {a.first-d.first, a.second-d.second};
    pair<int, int> b2 = {b.first-d.first, b.second-d.second};
    pair<int, int> c2 = {d.first-c.first, d.second-c.second};

    int ccw1 = ccw(c1, a1) * ccw(c1, b1);
    int ccw2 = ccw(c2, a2) * ccw(c2, b2);

    if(ccw1 <= 0 && ccw2 <= 0) {
        if(ccw1 == 0 && ccw2 == 0) {
            if(a > b) swap(a,b);
            if(c > d) swap(c,d);

            if(a <= d && b >= c) {
                cout << '1';
            } else {
                cout << '0';
            }
        } else {
            cout << '1';
        }
    } else {
        cout << '0';
    }

    return 0;
}