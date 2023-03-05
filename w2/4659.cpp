#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    bool acceptable;
    int c1, c2;
    char c3;
    while(true) {
        cin >> str;
        if(str.compare("end") == 0) break;

        acceptable = false;
        c1 = 0; c2 = 0; c3 = 'A';
        for(char c : str) {
            if(c3 == c && !(c == 'o' || c == 'e')) { acceptable = false; break; }
            c3 = c;

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { acceptable = true; c2++; c1 = 0; }
            else { c1++; c2 = 0; }

            if(c1 >= 3 || c2 >= 3) { acceptable = false; break;}
        }

        if(acceptable) cout << '<' << str << "> is acceptable.\n";
        else cout << '<' << str << "> is not acceptable.\n";
    }

    return 0;
}