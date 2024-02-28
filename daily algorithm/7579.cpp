#include <bits/stdc++.h>

using namespace std;

/*
    7579 앱

    1. 누적합 투포인터 실패
    2. DP ... 실패 (M을 memoization)
    3. 추가비용(c)를 memoization -> success
*/

int n, m, k;
pair<int,int> app[101];
int dp[101][10001];

int solve(int x) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(i != 0) dp[i][j] = dp[i-1][j];
            if(j >= app[i].second) {
                if(i == 0) dp[i][j] = app[i].first;
                else dp[i][j] = max(dp[i][j], dp[i-1][j - app[i].second] + app[i].first);
            }
        }
    }

    for(int i = 0; i <= k; i++) {
        if(dp[n-1][i] >= m) {
            return i;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> app[i].first;
    }

    for(int i = 0; i < n; i++) {
        cin >> app[i].second;
        k += app[i].second;
    }

    cout << solve(m);

    return 0;
}