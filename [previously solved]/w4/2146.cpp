#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int visited[101][101];
pair<int, int> dir[4] = {{0,1},{1,0},{-1,0},{0,-1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y, dx, dy;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> q, q2;
    int land = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!board[i][j] || visited[i][j])  continue;

            q.push({i,j});
            q2.push({i,j});
            visited[i][j] = land;
            while(!q.empty()) {
                tie(x,y) = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

                    if(!visited[dx][dy] && board[dx][dy]) {
                        q.push({dx,dy});
                        q2.push({dx,dy});
                        visited[dx][dy] = land;
                    }
                }
            }
            land++;
        }
    }

    int res = 0, tmp;
    while(!q2.empty()) {
        tie(x,y) = q2.front();
        q2.pop();

        for(int d = 0; d < 4; d++) {
            dx = x + dir[d].first;
            dy = y + dir[d].second;

            if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

            if(!visited[dx][dy] && !board[dx][dy]) {
                q2.push({dx,dy});
                board[dx][dy] = board[x][y] + 1;
                visited[dx][dy] = visited[x][y];
            } else if(visited[dx][dy] && visited[dx][dy] != visited[x][y]) {
                if(board[dx][dy] > board[x][y]) {
                    tmp = (board[x][y] - 1) * 2 + 1;
                } else {
                    tmp = (board[x][y] - 1) * 2;
                }

                res = (res ? min(res, tmp) : tmp);
            }
        }
    }

    cout << res << '\n';

    return 0;
}