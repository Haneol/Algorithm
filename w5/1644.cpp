#include<bits/stdc++.h>
using namespace std;

bool table[4000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int inx;
    vector<int> v;
    for(int i = 2; i <= n; i++) {
        if(table[i]) continue;
        v.push_back(i);
        inx = 0;
        while(inx <= n) {
            table[inx] = true;
            inx += i;
        }
    }

    int x = 0, y = 0, sum = 0, res = 0;
    while(x <= v.size() && y <= v.size()) {
        if(sum == n) {
            res++;
            sum += (v[y] - v[x]);
            x++; y++;
        } else if(sum < n) {
            sum += v[y];
            y++;
        } else if(sum > n) {
            sum -= v[x];
            x++;
        }
    }

    cout << res << '\n';

    return 0;
}