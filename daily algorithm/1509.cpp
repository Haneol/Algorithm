#include <bits/stdc++.h>

using namespace std;

/*
    1509 팰린드롬 분할
*/

int pal[2501][2501];
int dp_table[2501];
string str;

int palindrome(int start, int end) {
    if(pal[start][end] != 0) return pal[start][end];
    int x = start, y = end;
    while(start < end) {
        if(str[start] != str[end]) {
            return pal[x][y] = -1;
        }
        start++; end--;
    }

    return pal[x][y] = 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        for(int j = i; j >= 0; j--) {
            if(palindrome(j, i) == 1) {
                if(j > 0) {
                    if(dp_table[i] == 0) {
                        dp_table[i] = dp_table[j-1] + 1;
                    } else {
                        dp_table[i] = min(dp_table[i], dp_table[j-1]+1);
                    }
                } else {
                    dp_table[i] = 1;
                }
            }
        }
    }

    cout << dp_table[str.length()-1];

    return 0;
}

