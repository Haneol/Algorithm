#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int k, x;

    cin >> k;

    while(k--) {
        cin >> x;
        if(x == 0) s.pop();
        else s.push(x);
    }

    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';
}