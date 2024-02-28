#include <bits/stdc++.h>

using namespace std;

/*
    1005 ACM Craft
*/

int t, n, k;
int building[1001];
vector<int> order[1001];
int memo[1001][1001];

int solve(int x, int next) {
    if(!order[x].size()) return building[x];

    if(memo[next][x] != -1) return memo[next][x];

    for(int i = 0; i < order[x].size(); i++) {
        if(memo[next][x] < solve(order[x][i], x)) {
            memo[next][x] = solve(order[x][i], x);
        }
    }

    return memo[next][x] += building[x];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;

    while(t--) {
        cin >> n >> k;
        
        for(int i = 1; i <= n; i++) {
            cin >> building[i];
        }

        int x, y, goal;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            order[y].push_back(x);
        }

        cin >> goal;

        fill(&memo[0][0], &memo[n][n+1], -1);

        cout << solve(goal, goal) << '\n';

        for(int i = 1; i <= n; i ++) {
            order[i].clear();
        }
    }
}