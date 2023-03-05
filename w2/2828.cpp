#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, j, k;
    cin >> n >> m >> j;

    int s = 1, e = m;

    int res = 0;
    while(j--) {
        cin >> k;

        if(k < s) {
            res += (s - k);
            e = (e - s + k); s = k ;
        } else if(k > e) {
            res += (k - e);
            s = s + (k - e); e = k;
        }
    }

    cout << res << '\n';

    return 0;
}