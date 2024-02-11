#include <bits/stdc++.h>

using namespace std;

/*
    10942 팰린드롬?
*/

int n, m;
int pal[2001];
int dp_table[2001][2001];

void palindrome() {
    for(int i = 1; i <= n; i++) {
        dp_table[i][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(pal[i] == pal[i+1]) {
            dp_table[i][i+1] = 1;
        }
    }

    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= n - i + 1; j++) {
            if(dp_table[j+1][j+i-2] == 1 && pal[j] == pal[j+i-1]) {
                dp_table[j][j+i-1] = 1;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> pal[i];
    }

    palindrome();

    cin >> m;

    int s, e;
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << dp_table[s][e] << '\n';
    }

    return 0;
}