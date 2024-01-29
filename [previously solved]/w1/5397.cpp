#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L;
    string str;
    list<char> li;
    list<char>::iterator iter;

    cin >> L;

    while(L--) {
        cin >> str;
        
        li.clear();
        iter = li.begin();
        for(char c : str) {
            if(c == '<' && iter != li.begin()) iter--;
            else if (c == '>' && iter != li.end()) iter++;
            else if(c == '-' && iter != li.begin()) iter = li.erase(--iter);
            else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c >= '0' && c <= '9') li.insert(iter, c);
        }

        for(iter = li.begin(); iter != li.end(); iter++) cout << *iter;
        cout << '\n';
    }
}