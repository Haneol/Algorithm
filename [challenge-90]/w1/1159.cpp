#include<bits/stdc++.h>
using namespace std;

int arr[26];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        arr[s[0] - 'a']++;
    }

    bool flag = false;
    for(int i = 0; i < 26; i++)
        if(arr[i] >= 5) {
            cout << (char) (i + 'a');
            flag = true;
        }

    if(!flag) cout << "PREDAJA";

    return 0;
}