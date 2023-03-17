#include<bits/stdc++.h>
using namespace std;

char treasure_map[52][52];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    fill(&treasure_map[0][0], &treasure_map[51][52], 'W');
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> treasure_map[i][j];
        }
    }

    return 0;
}