#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, tmp;
    long long res = 0;
    cin >> n;

    stack<pair<int,int>> s;
    
    while(n--) {
        cin >> k;

        while(!s.empty() && s.top().first < k) {
            res += s.top().second;
            s.pop();
        }

        if(s.empty()) {
            s.push({k, 1});
        } else if(s.top().first == k) {
            tmp = s.top().second; 
            res += tmp;
            if(s.size() > 1) res += 1;
            s.pop();
            s.push({k, tmp+1});
        } else if(s.top().first > k) {
            res += 1;
            s.push({k, 1});
        }
    }

    cout << res << '\n';

    return 0;
}