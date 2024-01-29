#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, k, x, y, dx, dy;
    queue<pair<int, int>> q;
    vector<pair<int,int>> cabbage;
    int land[51][51];
    bool visited[51][51];

    pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

    cin >> T;

    while(T--) {
        cin >> m >> n >> k;

        fill(&land[0][0], &land[50][50], 0);
        fill(&visited[0][0], &visited[50][50], false);
        int output = 0;
        cabbage.clear();

        while(k--) {
            cin >> x >> y;
            land[y][x] = 1;
            cabbage.push_back({x,y});
        }

        for(auto i : cabbage) {
            if(visited[i.second][i.first]) continue;

            q.push(i);
            visited[i.second][i.first] = true;
            while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(dx < 0 || dx >= m || dy < 0 || dy >= n) continue;

                    if(!visited[dy][dx] && land[dy][dx]) q.push({dx, dy}), visited[dy][dx] = true;
                }
            }
            output++;
        }

        cout << output << '\n';
    }

    return 0;
}