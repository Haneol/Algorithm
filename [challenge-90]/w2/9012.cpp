#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<bool> v;
    stack<char> s;
    string str;
    while(n--) {
        while(!s.empty()) s.pop();

        cin >> str;
        for(char c : str) {
            if(c == '(') s.push(c);
            else if(c == ')') {
                if(!s.empty()) s.pop();
                else { s.push(')'); break; } 
            }
        }
        if(s.empty()) v.emplace_back(true);
        else v.emplace_back(false);
    }

    for(bool b : v) cout << (b ? "YES" : "NO") << '\n';

    return 0;
}