#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char c;
    cin >> n;

    stack<int> s;
    int res = 0, cnt = 0;
    while(n--) {
        do {c = cin.get();} while(c == ' ' || c == '\n');

        if(c == '(') {
            s.push(0);
        } else if(c == ')'){
            cnt = 0;
            while(!s.empty() && s.top() > 0) {
                cnt += s.top();
                s.pop();
            }
            
            if(!s.empty() && s.top() == 0) {
                s.pop();
                s.push(cnt+1);
            } else {
                s.push(cnt);
                s.push(-1);
            }
        }
    }

    cnt = 0;
    while(!s.empty()) {
        if(s.top() <= 0) cnt = 0;
        else cnt += s.top();
        s.pop();

        res = max(res, cnt);
    }

    cout << res * 2 << '\n';

    return 0;
}