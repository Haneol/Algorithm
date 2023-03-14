#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, tmp;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    stack<int> s;
    for(int i = v.size() - 1; i >= 0; i--) {
        while(!s.empty()) 
            if(v[i] >= s.top()) s.pop(); 
            else break;

        if(!s.empty()) {
            tmp = s.top();
            s.push(v[i]);
            v[i] = tmp;
        } else {
            s.push(v[i]);
            v[i] = -1;
        }

    }

    for(int i : v) cout << i << ' ';
    cout << '\n';

    return 0;
}