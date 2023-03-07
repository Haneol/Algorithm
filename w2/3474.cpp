#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, x, count;
    cin >> T;

    vector<int> v;
    while(T--) {
        cin >> n;

        x = 5;
        count = 0;
        while(n >= x) {
            count += (n / x);
            x *= 5;
        }

        v.emplace_back(count);
    }

    for(int i : v) cout << i << '\n';

    return 0;
}