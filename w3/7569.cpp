#include <bits/stdc++.h>

using namespace std;

int tomato[102][102][102];
tuple<int, int, int> dir[6] = {{1,0,0}, {0,1,0}, {0,0,1}, {-1,0,0,}, {0,-1,0}, {0,0,-1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h, x, y, z, dx, dy, dz;
    cin >> m >> n >> h;

    fill(&tomato[0][0][0], &tomato[101][101][101], -1);
    queue<tuple<int, int, int>> q;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++) 
            for(int k = 1; k <= m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) q.push({k,j,i});
            }

    int size = q.size();
    int cnt = 0;
    while(!q.empty()) {
        while(size--) {
            tie(x, y, z) = q.front();
            q.pop();

            for(int d = 0; d < 6; d++) {
                dx = x + get<0>(dir[d]);
                dy = y + get<1>(dir[d]);
                dz = z + get<2>(dir[d]);

                if(tomato[dz][dy][dx] == 0) {
                    tomato[dz][dy][dx] = 1;
                    q.push({dx, dy, dz});
                }
            }
        }
        size = q.size();
        cnt++;
    }
    
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= n; j++) 
            for(int k = 1; k <= m; k++)
                if (tomato[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }

    cout << cnt - 1 << '\n';

    return 0;
}