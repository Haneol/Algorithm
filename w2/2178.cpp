#include<bits/stdc++.h>
using namespace std;

int arr[102][102];
bool visited[102][102];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,tmp,x,y,d,dx,dy;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            tmp = cin.get();
            if(tmp == '\n') tmp = cin.get();
            arr[i][j] = tmp - '0';
        }

    queue<tuple<int, int, int> > q;
    q.push({1,1,1});
    while(!q.empty()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        d = get<2>(q.front());
        q.pop();

        if(!visited[x][y]) 
            if(x == n && y == m) break;
            else visited[x][y] = true;
        else continue;

        for(int i = 0; i < 4; i++) {
            dx = x + dir[i].first;
            dy = y + dir[i].second;

            if(!visited[dx][dy] && arr[dx][dy] == 1) q.push({dx, dy, d+1});
        }
    }

    cout << d << '\n';

    return 0;
}