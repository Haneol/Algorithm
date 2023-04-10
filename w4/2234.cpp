#include <bits/stdc++.h>
using namespace std;

int arr[50][50];
int t_arr[50][50];
bool visited[50][50];
pair<int,int> dir[4] = {{0,-1},{-1,0},{0,1},{1,0}};
vector<pair<pair<int,int>,int>> room_size;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int,int>> q;
    int cnt = 0, ssize, max_size = 0;
    int x, y, dx, dy;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {          
            ssize = 0;
            if(visited[i][j]) continue;
            visited[i][j] = true;
            cnt++;

            q.push({i, j});
            t_arr[i][j] = cnt - 1;
    
            ssize = 1;
            while(!q.empty()) {
                tie(x, y) = q.front(); q.pop();

                for(int d = 0; d < 4; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(dx < 0 || dy < 0 || dx >= m || dy >= n) continue;

                    if(!visited[dx][dy] && !(arr[x][y] & (1 << d))) {
                        q.push({dx,dy});
                        visited[dx][dy] = true;
                        t_arr[dx][dy] = cnt - 1;
                        ssize++;
                    }
                }
            }
            room_size.push_back({{i,j}, ssize});
            max_size = max(max_size, ssize);
        }
    }

    memset(visited, 0, sizeof(visited));
    
    int max_size2 = 0;
    vector<int> tmp;
    for(int i = 0; i < room_size.size(); i++) {
        
        q.push(room_size[i].first);
        tmp.clear();

        while(!q.empty()) {
            tie(x, y) = q.front(); q.pop();

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(dx < 0 || dy < 0 || dx >= m || dy >= n) continue;

                if(!visited[dx][dy] && !(arr[x][y] & (1 << d))) {
                    q.push({dx,dy});
                    visited[dx][dy] = true;
                } else if(t_arr[x][y] != t_arr[dx][dy]) {
                    tmp.push_back(t_arr[dx][dy]);
                }
            }
        }

        for(int j = 0; j < tmp.size(); j++)
            max_size2 = max(max_size2, (room_size[i].second + room_size[tmp[j]].second));
    }


    cout << cnt << '\n' << max_size << '\n' << max_size2 << '\n';

    return 0;
}