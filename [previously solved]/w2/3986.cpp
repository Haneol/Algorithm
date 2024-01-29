#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    stack<char> s;

    cin >> n;

    int output = 0;
    while (n--) {
        cin >> str;

        for(char c : str) {
            if(s.empty() || s.top() != c) s.push(c);
            else s.pop();
        }

        if (s.empty()) output++;
        else while(!s.empty()) s.pop();
    }

    cout << output << '\n';

    return 0;
}