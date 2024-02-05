#include <bits/stdc++.h>

using namespace std;

/*
    2166 다각형의 면적
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    long long x, y;
    double res = 0;
    cin >> n;

    vector<pair<long long,long long>> poly;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        poly.push_back({x,y});
    }

    for(int i = 0; i < n-1; i++) {
        res += (poly[i].first * poly[i+1].second - poly[i+1].first * poly[i].second);
    }

    res += (poly[n-1].first * poly[0].second - poly[0].first * poly[n-1].second);

    cout << fixed;
    cout.precision(1);
    cout << abs(res / 2) << '\n';

    return 0;
}