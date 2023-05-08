#include<bits/stdc++.h>
using namespace std;

int n;
int cost[1001][3];
int dp_table[1002][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp_table[i+1][j] = cost[i][j] + min(dp_table[i][(j+1) % 3], dp_table[i][(j+2) % 3]);
        }
    }

    cout << min(min(dp_table[n][0], dp_table[n][1]), dp_table[n][2]) << '\n';

    return 0;
}