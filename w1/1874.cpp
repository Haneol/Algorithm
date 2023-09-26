#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    vector<char> v;
    int n, k;

    cin >> n;

    int i = 1;
    while(n--) {
        cin >> k;

        while(s.empty() || !s.empty() && s.top() < k) {
            s.push(i++);
            v.push_back('+');
        }

        if(!s.empty() && s.top() == k) {
            s.pop();
            v.push_back('-');
        }
    }

    if(s.empty()) {
        for(char c : v)
            cout << c << '\n';
    } else {
        cout << "NO\n";
    }
}