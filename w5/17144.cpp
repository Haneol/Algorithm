#include<bits/stdc++.h>
using namespace std;

int room[50][50];
int delta[50][50];
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int air_purifier[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c,t;
    cin >> r >> c >> t;

    int k = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> room[i][j];
            if(room[i][j] == -1) air_purifier[k++] = i;
        }
    }

    int cnt, dx, dy;
    while(t--) {
        memset(delta, 0, sizeof(delta));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(room[i][j] >= 5) {
                    cnt = 0;
                    for(int d = 0; d < 4; d++) {
                        dx = i + dir[d].first;
                        dy = j + dir[d].second;
                        
                        if((dx == air_purifier[0] && dy == 0)
                            || (dx == air_purifier[1] && dy == 0)) continue;

                        if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;

                        delta[dx][dy] += room[i][j] / 5;
                        cnt++;
                    }
                    delta[i][j] -= (room[i][j] / 5) * cnt;
                }
            }
        }

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                room[i][j] += delta[i][j];

        for(int i = air_purifier[0]-2; i >= 0; i--) room[i+1][0] = room[i][0];
        for(int i = 1; i < c; i++) room[0][i-1] = room[0][i];
        for(int i = 1; i <= air_purifier[0]; i++) room[i-1][c-1] = room[i][c-1];
        for(int i = c-2; i >= 1; i--) room[air_purifier[0]][i+1] = room[air_purifier[0]][i];
        room[air_purifier[0]][1] = 0;

        for(int i = air_purifier[1]+2; i < r; i++) room[i-1][0] = room[i][0];
        for(int i = 1; i < c; i++) room[r-1][i-1] = room[r-1][i];
        for(int i = r-2; i >= air_purifier[1]; i--) room[i+1][c-1] = room[i][c-1];
        for(int i = c-2; i >= 1; i--) room[air_purifier[1]][i+1] = room[air_purifier[1]][i];
        room[air_purifier[1]][1] = 0;
    }


    int res = 2;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            res += room[i][j];
    
    cout << res << '\n';

    return 0;
}