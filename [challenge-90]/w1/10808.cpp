#include<bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    
    cin >> str;

    for(char c : str) {
        int tmp = c - 'a';
        arr[tmp]++;
    }

    for(int i = 0; i < 26; i++)
        cout << arr[i] << ' ';

    return 0;
}