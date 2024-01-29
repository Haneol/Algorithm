#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    double v1, v2;
    string post;
    vector<double> v;
    stack<double> s;

    cin >> n >> post;

    while(n--) 
        cin >> k,
        v.push_back(k);

    for(char c : post) {
        if(c >= 'A' && c <= 'Z') {
            s.push(v[c-'A']);
        }
        else {
            v2 = s.top(); s.pop();
            v1 = s.top(); s.pop();

            if (c == '+') s.push(v1 + v2);
            else if (c == '-') s.push(v1 - v2);
            else if (c == '*') s.push(v1 * v2);
            else if (c == '/') s.push(v1 / v2);
        }
    }

    cout << fixed;
    cout.precision(2);
    
    cout << s.top() << '\n';

    return 0;
}