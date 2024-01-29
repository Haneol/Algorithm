#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n, x, k;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }

    cin >> x;

    sort(v.begin(), v.end());

    int s = 0, e = n-1, cnt = 0;
    while(s < e) {
        if(v[s] + v[e] == x) {
            cnt++;
            s++;
        } else if(v[s] + v[e] < x) {
            s++;
        } else {
            e--;
        }
    }

    cout << cnt;
}