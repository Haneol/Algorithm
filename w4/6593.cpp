#include <bits/stdc++.h>

using namespace std;

char building[31][31][31];
int visited[31][31][31];
tuple<int, int, int> dir[6] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0}, {0,0,-1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, R, C, x, y, z, dx, dy, dz;
    queue<tuple<int,int,int>> q;

    while(true) {
        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0) break;

        fill(&visited[0][0][0], &visited[30][30][30], 0);
        while(!q.empty()) q.pop();
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S') q.push({i,j,k}), visited[i][j][k] = 1;
                }
            }
        }

        while(!q.empty()) {
            tie(x,y,z) = q.front(); q.pop();

            for(int d = 0; d < 6; d++) {
                dx = x + get<0>(dir[d]);
                dy = y + get<1>(dir[d]);
                dz = z + get<2>(dir[d]);

                if(dx < 0 || dy < 0 || dz < 0 || dx >= L || dy >= R || dz >= C) continue;

                if(!visited[dx][dy][dz] && building[dx][dy][dz] != '#') {
                    if(building[dx][dy][dz] == 'E') {
                        cout << "Escaped in " << visited[x][y][z] << " minute(s).\n";
                        goto LABEL;
                    }
                    q.push({dx,dy,dz});
                    visited[dx][dy][dz] = visited[x][y][z] + 1;
                }
            }
        }
        cout << "Trapped!\n";
        LABEL:;
    }

    return 0;
}