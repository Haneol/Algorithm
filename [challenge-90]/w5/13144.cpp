#include<bits/stdc++.h>
using namespace std;

bool checked[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    
    long long res = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        cin >> m;
        if(checked[m]) {
            while(!q.empty() && q.front() != m) {
                checked[q.front()] = false;
                q.pop();
            }
            q.pop();
        } else checked[m] = true;
        
        q.push(m);
        res += q.size();
    }

    cout << res << '\n';

    return 0;
}