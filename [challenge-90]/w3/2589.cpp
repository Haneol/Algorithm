#include<bits/stdc++.h>
using namespace std;

char treasure_map[52][52];
bool visited[52][52];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > v;
    fill(&treasure_map[0][0], &treasure_map[51][52], 'W');
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> treasure_map[i][j];
            if(treasure_map[i][j] == 'L') v.push_back({i, j});
        }
    }

    queue<pair<int, int> > q;
    int times, dist, output = 0;
    int x, y, dx, dy;
    for(auto k : v) {
        memset(visited, false, sizeof(visited));
        dist = 0;
        q.push(k);
        while(!q.empty()) {
            times = q.size();
            while(times--) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                if(visited[x][y]) continue;
                visited[x][y] = true;

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(!visited[dx][dy] && treasure_map[dx][dy] == 'L') q.push({dx, dy});
                }
            }
            dist++;
        }
        output = max(output, dist);
    }

    cout << output - 1 << '\n';

    return 0;
}