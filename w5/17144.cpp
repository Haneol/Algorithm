#include<bits/stdc++.h>
using namespace std;

int room[50][50];
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

    int cnt, tmp, dx, dy;
    while(t--) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(room[i][j] >= 5) {
                    cnt = 0;
                    for(int d = 0; d < 4; d++) {
                        dx = i + dir[d].first;
                        dy = j + dir[d].second;
                        
                        if(dx == air_purifier[0] && dy == 0
                            || dx == air_purifier[1] && dy == 0) continue;

                        if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;

                        room[dx][dy] += room[i][j] / 5;
                        cnt++;
                    }
                    room[i][j] -= (room[i][j] / 5) * cnt;
                }
            }
        }

        tmp = room[0][0];
        for(int i = air_purifier[0] - 1; i > 0; i++) room[i][0] = room[i-1][0];
        for(int i = 1; i < c; i++) room[0][i-1] = room[0][i]; // left
        for(int i = air_purifier[0]; i > 0; i--) room[i-1][c-1] = room[i][c-1]; // up
        for(int i = c-2; i > 0; i--) room[air_purifier[0]][i+1] = room[air_purifier[0]][i];
        room[air_purifier[0]][0] = 0; // right
        
        tmp = 
    }
    

    return 0;
}