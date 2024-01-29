#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n;

    long long sum = 0;
    stack<pair<int,int>> s;
    for(int i = 0; i < n; i++) {
        cin >> h;

        while(!s.empty() && s.top().first <= h) {
            sum += (i - s.top().second - 1);
            s.pop();
        }

        s.push({h,i});
    }
    
    if(!s.empty()) {
        int last = s.top().second;
        s.pop();

        while(!s.empty()) {
            sum += last - s.top().second;
            s.pop();
        }
    }

    cout << sum << '\n';

    return 0;
}