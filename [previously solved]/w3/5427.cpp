#include <bits/stdc++.h>

using namespace std;

char building[1002][1002];
int visited[2][1002][1002];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, w, h, x, y, dx, dy;
    queue<pair<int,int>> q;
    vector<pair<int,int>> fire;
    bool flag;

    cin >> T;

    while(T--) {
        cin >> w >> h;

        while(!q.empty()) q.pop();
        fire.clear();
        fill(&building[0][0], &building[h+1][w+1], '+');
        fill(&visited[0][0][0], &visited[1][h+1][w+1], 0);

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> building[i][j];
                if(building[i][j] == '@') {
                    q.push({i,j});
                    visited[0][i][j] = 1;
                }
                else if(building[i][j] == '*') {
                    fire.push_back({i,j});
                    visited[1][i][j] = 1;
                }
            }
        }

        for(auto a : fire) q.push(a);

        flag = false;
        while(!q.empty()) {
            tie(x,y) = q.front(); q.pop();

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;
                
                if(building[x][y] == '@') {
                    if(!visited[0][dx][dy] && building[dx][dy] == '.') {
                        q.push({dx, dy});
                        building[dx][dy] = '@';
                        visited[0][dx][dy] = visited[0][x][y] + 1;
                    } else if(building[dx][dy] == '+') {
                        cout << visited[0][x][y] << '\n';
                        flag = true;
                        break;
                    }
                } else if(building[x][y] == '*') {
                    if(!visited[1][dx][dy] && (building[dx][dy] == '.' || building[dx][dy] == '@')) {
                        q.push({dx, dy});
                        building[dx][dy] = '*';
                        visited[1][dx][dy] = 1;
                    }
                }
            }

            if(flag) break;
        }

        if(!flag) cout << "IMPOSSIBLE\n";
    }

    return 0;
}