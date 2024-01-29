#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> k, v.push_back(k);

    stable_sort(v.begin(), v.end());

    for(int i : v) cout << i << '\n';

    return 0;
}