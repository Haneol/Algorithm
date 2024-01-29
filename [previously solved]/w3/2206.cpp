#include <bits/stdc++.h>

using namespace std;

int board[1000][1000];
int visited[2][1002][1002];
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y, dx, dy;
    string str;
    queue<pair<int, int>> q;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            board[i][j] = str[j] - '0';
        }
    }

    q.push({0,0});
    visited[0][0][0] = 1;
    while(!q.empty()) {
        tie(x,y) = q.front(); q.pop();

        if(x == n-1 && y == m-1) {
            if(visited[1][x][y]) {
                cout << visited[1][x][y] << '\n';
                return 0;
            } else {
                cout << visited[0][x][y] << '\n';
                return 0;
            }
        }

        for(int d = 0; d < 4; d++) {
            dx = x + dir[d].first;
            dy = y + dir[d].second;

            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;

            if(visited[0][x][y] && !visited[0][dx][dy]) {
                q.push({dx,dy});
                if(board[dx][dy]) visited[1][dx][dy] = visited[0][x][y] + 1;
                else visited[0][dx][dy] = visited[0][x][y] + 1;
            }

            if(visited[1][x][y] && !visited[1][dx][dy] && !board[dx][dy]) {
                q.push({dx,dy});
                visited[1][dx][dy] = visited[1][x][y] + 1;
            }
        }
    }

    cout << "-1\n";

    return 0;
}