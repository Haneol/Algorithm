#include<bits/stdc++.h>
using namespace std;

int arr[301][301];
bool visited[301][301];
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    int start[2], end[2];

    cin >> r >> c >> start[0] >> start[1] >> end[0] >> end[1];
    start[0]--; start[1]--; end[0]--; end[1]--;


    int tmp;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            do { tmp = cin.get(); } while(tmp == ' ' || tmp == '\n');
            if(tmp == '#' || tmp == '*') arr[i][j] = 2;
            arr[i][j] = tmp - '0';
        }
    }

    queue<pair<int,int>> q, bq;
    bq.push({start[0], start[1]});

    int x,y,dx,dy,t=0;
    while(!bq.empty()) {
        while(!bq.empty()) { q.push(bq.front()); arr[bq.front().first][bq.front().second] = 0; bq.pop(); }
        while(!q.empty()) {
            tie(x,y) = q.front(); q.pop();

            if(visited[x][y]) continue;
            visited[x][y] = true;

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;

                if(!visited[dx][dy]) {
                    if(!arr[dx][dy]) q.push({dx,dy});
                    else if(arr[dx][dy] == 1) bq.push({dx,dy});
                    else if(dx == end[0] && dy == end[1]) {
                        cout << t+1 << '\n';
                        return 0;
                    }
                }
            }
        }
        t++;
    }

    return 0;
}