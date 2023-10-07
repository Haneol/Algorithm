#include <bits/stdc++.h>

using namespace std;

int board[101][101];
bool visited[101][101];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x, y, x2, y2, dx, dy;
    cin >> m >> n >> k;

    while(k--) {
        cin >> y >> x >> y2 >> x2;
        for(int i = y; i < y2; i++) {
            for(int j = x; j < x2; j++) {
                board[i][j] = 1;
            }
        }
    }

    queue<pair<int,int>> q;
    int cnt = 0;
    vector<int> size;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] || visited[i][j]) continue;

            q.push({i,j});
            visited[i][j] = true;
            cnt++;
            size.push_back(1);
            while(!q.empty()) {
                tie(y,x) = q.front(); q.pop();

                for(int d = 0; d < 4; d++) {
                    dy = y + dir[d].first;
                    dx = x + dir[d].second;

                    if(dy < 0 || dx < 0 || dy >= n || dx >= m) continue;

                    if(!visited[dy][dx] && !board[dy][dx]) {
                        q.push({dy,dx});
                        visited[dy][dx] = true;
                        size[cnt-1]++;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';
    sort(size.begin(), size.end());
    for(auto a : size) cout << a << ' ';

    return 0;
}