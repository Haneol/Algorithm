#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, tmp;
    cin >> n >> k;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(i == 0) v.push_back(tmp);
        else v.push_back(v[i-1] + tmp);
    }

    int max = -999999999;
    for(int i = k - 1; i < n; i++) {
        if(i < k) max = max < v[i] ? v[i] : max;
        else max = max < v[i] - v[i-k] ? v[i] - v[i-k] : max;
    }

    cout << max << '\n';

    return 0;
}