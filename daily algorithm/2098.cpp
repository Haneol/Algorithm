#include <bits/stdc++.h>

using namespace std;

/*
    2098 외판원 순회
    
    다시 풀어보기 -> 이해 똑바로 하기
*/

int n;
int cost[16][16];
int memo[1 << 16][16];

int solve(int x, int cur) {

    if(x == (1 << n) - 1) {
        if(cost[cur][0]) return cost[cur][0];
        else return INT32_MAX;
    }

    if (memo[x][cur]) return memo[x][cur];
    
    memo[x][cur] = INT32_MAX;
    for(int i = 0; i < n; i++) {
        if(!(x & (1 << i)) && cost[cur][i]) {
            int slv = solve(x | (1 << i), i);
            int tmp = slv == INT32_MAX ? slv : slv + cost[cur][i];
            if (memo[x][cur] > tmp) memo[x][cur] = tmp;
        }
    }
    return memo[x][cur];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << solve(1, 0);

    return 0;
}