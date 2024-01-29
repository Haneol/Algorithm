#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, tmp;
    bool reverse, error;
    string func, list;
    deque<int> q;

    cin >> T;

    while(T--) {
        tmp = 0;
        reverse = error = false;
        q.clear();

        cin >> func >> n >> list;

        for(char c : list) {
            if(c >= '0' && c <= '9') tmp = tmp * 10 + (c-'0');
            else if (tmp != 0) q.push_back(tmp), tmp = 0;
        }

        for(char c : func) {
            if(c == 'R') {
                reverse = !reverse;
            } else if (c == 'D') {
                if(q.empty()) {
                    error = true;
                    break;
                } else {
                    reverse ? q.pop_back() : q.pop_front();
                }
            }
        }

        if (error) cout << "error\n";
        else {
            cout << '[';
            if(reverse) {
                for(int i = q.size() - 1; i >= 0; i--) {
                    if(i == 0) cout << q[i];
                    else cout << q[i] << ',';
                }
            } else {
                for(int i = 0; i < q.size(); i++) {
                    if(i == q.size() - 1) cout << q[i];
                    else cout << q[i] << ',';
                }
            }
            cout <<"]\n";
        }
    }

    return 0;
}