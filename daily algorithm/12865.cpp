#include <bits/stdc++.h>

using namespace std;

/*
    12865 평범한 배낭

    1. 첫번째 접근 : 재귀식 접근 - 틀
    2. 두번째 접근 : DP - 틀
        - Memoization 실패, 무게에 대한 가치를 memo 하는 건 맞다. 하지만 논리적으로 틀림. 같은 무게가 같은 가치를 가지고 있다고 기록된다 하더라도, 해당 무게에 도달한 방법이 다르다면, 미래에 도달할 방법 역시 달라지므로 같다 볼 수 없고, 이를 메모이제이션 할 수 없다.
*/

int n, k, w, v;
int dp_table[100001][101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> w >> v;
        for(int j = 1; j < k + 1; j++) {
            if(w <= j) {
                dp_table[j][i] = max(dp_table[j-w][i-1] + v, dp_table[j][i-1]);
            } else {
                dp_table[j][i] = dp_table[j][i-1];
            }
        }
    }

    cout << dp_table[k][n-1] << '\n';

    return 0;
}