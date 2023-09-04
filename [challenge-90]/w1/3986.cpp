#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, output = 0;
    cin >> n;

    stack<char> s;
    string str;

    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            if(s.empty()) {
                s.push(str[j]);
            } else if(s.top() == str[j]) {
                s.pop();
            } else {
                s.push(str[j]);
            }
        }

        if(s.empty()) output++;
        else {
            while(!s.empty()) s.pop();
        }
    }

    cout << output << '\n';

    return 0;
}