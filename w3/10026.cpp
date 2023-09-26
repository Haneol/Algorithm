#include <bits/stdc++.h>

using namespace std;

char painting[102][102];
bool visited[102][102];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y, dx, dy;
    cin >> n;

    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) painting[i+1][j+1] = str[j];
    }

    queue<pair<int, int>> q;
    int cnt = 0, cnt_rg = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j]) continue;

            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(!visited[dx][dy] && painting[x][y] == painting[dx][dy]) q.push({dx, dy}), visited[dx][dy] = true;
                }
            }
            cnt++;
        }
    }

    fill(&visited[0][0], &visited[101][101], false);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j]) continue;

            q.push({i,j});
            visited[i][j] = true;
            while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(!visited[dx][dy] && (painting[x][y] == painting[dx][dy] || (painting[x][y] == 'R' && painting[dx][dy] == 'G' || painting[x][y] == 'G' && painting[dx][dy] == 'R')))
                        q.push({dx, dy}), visited[dx][dy] = true;
                }
            }
            cnt_rg++;
        }
    }

    cout << cnt << ' ' << cnt_rg << '\n';

    return 0;
}