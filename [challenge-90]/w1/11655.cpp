#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    
    getline(cin, str);

    for(char c : str) {
        if(c >= 'a' && c <= 'z')
            cout << (char) ((((c - 'a') + 13) % 26) + 'a');
        else if(c >= 'A' && c <= 'Z')
            cout << (char) ((((c - 'A') + 13) % 26) + 'A');
        else cout << c;
    }

    return 0;
}