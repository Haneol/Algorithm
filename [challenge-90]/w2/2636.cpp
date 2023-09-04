#include<bits/stdc++.h>
using namespace std;

int arr[102][102];
bool visited[102][102];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    fill(&arr[0][0], &arr[101][101], 2);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];
             
    int x, y, dx, dy, count, times = 0;
    bool flag, flag2;
    queue<pair<int, int> > q;
    while(true) {
        q.push({1,1});
        memset(visited, false, sizeof(visited));
        count = 0;
        flag2 = false;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if(visited[x][y]) continue;
            visited[x][y] = true;

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(!visited[dx][dy] && arr[dx][dy] == 0) q.push({dx, dy});
                else if(!visited[dx][dy] && arr[dx][dy] == 1) { 
                    arr[dx][dy] = 0; 
                    visited[dx][dy] = true; 
                    count++; flag2 = true; 
                }
            }
        }

        flag = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(arr[i][j] == 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag2) {times = -1; break;}
        else if(flag) times++;
        else break;
    }

    cout << times + 1 << '\n' << count << '\n';

    return 0;
}