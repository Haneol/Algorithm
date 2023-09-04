#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, k;
    string op, lst;
    bool dir, flag;
    deque<int> q;

    cin >> T;

    while(T--) {
        cin >> op >> n >> lst;

        k = 0; dir = false; flag = false;
        while(!q.empty()) q.pop_back();

        for(char c : lst) {
            if(c >= '0' && c <= '9') {
                k = k * 10 + (c - '0');
            } else if(k != 0) {
                q.push_back(k);
                k = 0;
            }
        }

        for(char c : op) {
            if(c == 'R') {
                dir = !dir;
            } else if(c == 'D') {
                if(q.empty()) {
                    cout << "error" << '\n';
                    flag = true;
                    break;
                }
                
                if(dir) q.pop_back();
                else q.pop_front();
            }
        }

        if(flag) continue;

        cout << '[';
        if(dir) {
            while(!q.empty()) {
                cout << q.back(); q.pop_back();
                if(!q.empty()) cout << ',';
            }
        } else {
            while(!q.empty()) {
                cout << q.front(); q.pop_front();
                if(!q.empty()) cout << ',';
            }
        }
        cout << "]\n";
    }

    return 0;
}