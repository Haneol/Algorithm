#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> v;
    stack<char> s;
    string str;
    while(true) {
        getline(cin, str);
        if(str.compare(".") == 0) break;

        while(!s.empty()) s.pop();
        for(char c : str) {
            if(c == '(' || c == '[') s.push(c);
            else if(c == ')') {
                if(!s.empty()) 
                    if(s.top() == '(') s.pop();
                    else { s.push(c); break; }
                else { s.push(c); break; } 
            } else if(c == ']') {
                if(!s.empty()) 
                    if(s.top() == '[') s.pop();
                    else { s.push(c); break; }
                else { s.push(c); break; } 
            }
        }
        if(s.empty()) v.emplace_back(true);
        else v.emplace_back(false);
    }

    for(bool b : v) cout << (b ? "yes" : "no") << '\n';

    return 0;
}