#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for(int i = 0; i < str.length() / 2;  i++) {
        if(str[i] != str[str.length() - 1 - i])
        {
            cout << 0 << '\n'; return 0;
        }
    }
    cout << 1 << '\n';    

    return 0;
}