#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> s;
    int n, k;

    cin >> n;

    int prev = 0;
    for(int i = 1; i <= n; i++) {
        cin >> k;

        while(!s.empty() && s.top().first < k) s.pop();

        if(s.empty()) cout << "0 ";
        else cout << s.top().second << ' ';

        s.push({k, i});
    }
}