#include<bits/stdc++.h>
using namespace std;

int R,C,M;
int ocean[100][100];
int shark[10001][5];
pair<int,int> dir[4] = {{-1,0},{1,0},{0,1},{0,-1}};

void reverse_dir(int shark_num) {
    if(shark[shark_num][3] == 0) shark[shark_num][3]++;
    else if(shark[shark_num][3] == 1) shark[shark_num][3]--;
    else if(shark[shark_num][3] == 2) shark[shark_num][3]++;
    else if(shark[shark_num][3] == 3) shark[shark_num][3]--;
}

int new_position(int shark_num, int x, bool vertical) {
    if(vertical) {
        int new_x = x % (2*(R-1));
        if(new_x < 0) {
            reverse_dir(shark_num);
            new_x *= -1;
        }

        if(new_x < R) return new_x;
        else {
            reverse_dir(shark_num);
            return (2*(R-1)) - new_x;
        }
    } else {
        int new_x = x % (2*(C-1));
        if(new_x < 0) {
            reverse_dir(shark_num);
            new_x *= -1;
        }

        if(new_x < C) return new_x;
        else {
            reverse_dir(shark_num);
            return (2*(C-1)) - new_x;
        }
    }
}

void move() {
    int new_ocean[100][100] = {0,};

    int x,y,s,d;
    for(int i = 1; i <= M; i++) {
        if(shark[i][4]) {
            d = shark[i][3];
            s = shark[i][2];
            x = new_position(i, shark[i][0] + dir[d].first * s, true);
            y = new_position(i, shark[i][1] + dir[d].second * s, false);

            if(!new_ocean[x][y]) {
                shark[i][0] = x;
                shark[i][1] = y;
                new_ocean[x][y] = i;
            }
            else if(shark[new_ocean[x][y]][4] < shark[i][4]) {
                shark[new_ocean[x][y]][4] = 0;
                shark[i][0] = x;
                shark[i][1] = y;
                new_ocean[x][y] = i;
            } else if(shark[new_ocean[x][y]][4] > shark[i][4]) {
                shark[i][4] = 0;
            }
        }
    }
    
    copy(&new_ocean[0][0], &new_ocean[0][0]+10000, &ocean[0][0]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    int r,c,s,d,z;
    int shark_num = 1;
    for(int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        ocean[r-1][c-1] = shark_num;
        shark[shark_num][0] = r-1;
        shark[shark_num][1] = c-1; 
        shark[shark_num][2] = s;
        shark[shark_num][3] = d-1;
        shark[shark_num][4] = z;
        shark_num++;
    }

    int res = 0;
    for(int angler = 0; angler < C; angler++) {      
        for(int i = 0; i < R; i++) {
            if(ocean[i][angler]) {
                res += shark[ocean[i][angler]][4];
                shark[ocean[i][angler]][4] = 0;
                ocean[i][angler] = 0;
                break;
            }
        }

        move();
    }

    cout << res << '\n';

    return 0;
}