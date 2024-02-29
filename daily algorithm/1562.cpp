#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

/*
    1562 계단 수
*/

int n;
int memo[101][11][1024];

int solve(int x, int y, int v) {
    if(x == 0) {
        if(!(v & ~(1 << y))) {
            return memo[x][y][v] = 1;
        } else {
            return 0;
        }
    }

    if(memo[x][y][v]) return memo[x][y][v];

    return memo[x][y][v] = ((y > 0 ? solve(x-1, y-1, (v & ~(1 << y))) : 0) + (y < 9 ? solve(x-1, y+1, (v & ~(1 << y))) : 0)) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    int res = 0;
    for(int i = 1; i <= 9; i++) 
        res = (res + solve(n-1, i, 1023)) % MOD;

    cout << res;

    return 0;
}