#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    string str;
    cin >> str;

    stack<int> s;
    for(char c : str) {
        if(c == '(') s.push(0);
        else if(c == '[') s.push(1);
        else if(c == ')') {
            x = 0;
            while(!s.empty() && s.top() != 0) {
                if(s.top() == 1) {
                    cout << "0\n";
                    return 0;
                }

                x += s.top(); s.pop();
            }

            if (!s.empty() && s.top() == 0) s.pop(), x ? s.push(x*2) : s.push(2);
            else {
                cout << "0\n";
                return 0;
            }
        } else if(c == ']') {
            x = 0;
            while(!s.empty() && s.top() != 1) {
                if(s.top() == 0) {
                    cout << "0\n";
                    return 0;
                }

                x += s.top(); s.pop();
            }
            if (!s.empty() && s.top() == 1) s.pop(), x ? s.push(x*3) : s.push(3);
            else {
                cout << "0\n";
                return 0;
            }
        }
    }

    x = 0;
    while(!s.empty()) {
        if (s.top() == 0 || s.top() == 1) {
            cout << "0\n";
            return 0;
        }
        x += s.top();
        s.pop();
    }

    cout << x << '\n';

    return 0;
}