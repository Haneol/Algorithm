#include<bits/stdc++.h>
using namespace std;

int arr[50][50];
bool visited[50][50];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    int x, y, dx, dy;
    int union_sum;
    int times = 0;
    bool flag = true;

    while(flag) {
        memset(visited, false, sizeof(visited));
        flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v.clear();
                union_sum = 0;
                if(visited[i][j]) continue;
                q.push({i, j});
                while(!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();

                    if(visited[x][y]) continue;
                    visited[x][y] = true;
                    v.push_back({x,y});
                    union_sum += arr[x][y];

                    for(int d = 0; d < 4; d++) {
                        dx = x + dir[d].first;
                        dy = y + dir[d].second;

                        if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

                        if(!visited[dx][dy] && abs(arr[x][y] - arr[dx][dy]) >= l && abs(arr[x][y] - arr[dx][dy]) <= r) {
                            flag = true;
                            q.push({dx,dy});
                        }
                    }
                }
                for(int k = 0; k < v.size(); k++) arr[v[k].first][v[k].second] = union_sum / (int) (v.size());
            }
        }
        if(flag) times++;
    }

    cout << times << '\n';

    return 0;
}