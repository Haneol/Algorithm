#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    string cmp = "";
    for(int i = 0; i < str.length(); i++) cmp += "0";
    
    int len = str.length();
    while(len--) {
        int i;
        if(str.find("pi") != string::npos) {
            i = str.find("pi");
            str = str.replace(i,2, "00");
            len -= 1;
        } else if (str.find("ka") != string::npos) {
            i = str.find("ka");
            str = str.replace(i,2, "00");
            len -= 1;
        } else if (str.find("chu") != string::npos) {
            i = str.find("chu");
            str = str.replace(i,3, "000");
            len -= 2;
        }
    }

    if(cmp == str) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}