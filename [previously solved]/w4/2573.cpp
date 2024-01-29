#include <bits/stdc++.h>

using namespace std;

int board[302][302];
int next_v[302][302];
bool visited[302][302];
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y, dx, dy;
    cin >> n >> m;

    queue<pair<int,int>> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    bool flag;
    while(true) {
        flag = false;
        fill(&next_v[0][0], &next_v[n+1][m+1], 0);
        fill(&visited[0][0], &visited[n+1][m+1], false);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(visited[i][j] || !board[i][j]) continue;

                if(flag && !visited[i][j]) {
                    cout << time << '\n';
                    return 0;
                } else flag = true;
                
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()) {
                    tie(x,y) = q.front(); q.pop();

                    for(int d = 0; d < 4; d++) {
                        dx = x + dir[d].first;
                        dy = y + dir[d].second;

                        if(!board[dx][dy]) next_v[x][y]++;
                        else if(!visited[dx][dy] && board[dx][dy]) q.push({dx,dy}), visited[dx][dy] = true;
                    }
                }
            }
        }

        if(!flag) break;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                board[i][j] -= next_v[i][j];
                if (board[i][j] < 0) board[i][j] = 0;
            }
        }

        time++;
    }

    cout << 0 << '\n';
    return 0;
}