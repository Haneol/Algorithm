#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, e;
    cin >> str >> e;

    deque<char> s, s2;

    int i;
    for(char c : str) {
        s.push_front(c);

        i = e.size() - 1;
        while(!s.empty() && s.front() == e[i]) {
            s2.push_front(s.front()); s.pop_front();
            i--;
            if(i < 0) {
                while(!s2.empty()) s2.pop_front();
                break;
            }
        }
        while(!s2.empty()) {
            s.push_front(s2.front()); s2.pop_front();
        }
    }

    if(!s.empty()) {
        while(!s.empty()) {
            cout << s.back();
            s.pop_back();
        }
        cout << '\n';
    } else {
        cout << "FRULA\n";
    }
}