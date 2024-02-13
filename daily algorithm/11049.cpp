#include <bits/stdc++.h>

using namespace std;

/*
    11049 행렬 곱셈 순서
*/

int n;
int d[502];
int memo[501][501];

int solve(int x, int y) {
    if(x == y) return 0;
    if(memo[x][y] != 0) return memo[x][y];

    for(int k = x; k < y; k++) {
        memo[x][y] = min(memo[x][y] == 0 ? INT32_MAX : memo[x][y], solve(x, k) + solve(k+1, y) + d[x] * d[k+1] * d[y+1]);
    }

    return memo[x][y];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            cin >> d[0] >> d[1];
        } else {
            int tmp;
            cin >> tmp >> d[i+1];
        }
    }

    cout << solve(0, n-1);

    return 0;
}