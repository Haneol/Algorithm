#include<bits/stdc++.h>
using namespace std;

int r,c,k,counts;
char arr[6][6];
bool tmp_arr[6][6];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

void bt(int x, int y, int t, bool visited[][6]) {
    if(x == 0 && y == c-1) {
        if(t == k-1) counts++;
        return;
    }

    int dx, dy;
    for(int d = 0; d < 4; d++) {
        dx = x + dir[d].first;
        dy = y + dir[d].second;

        if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;
        if(!visited[dx][dy] && arr[dx][dy] == '.') {
            copy(&visited[0][0], &visited[5][6], &tmp_arr[0][0]);
            tmp_arr[x][y] = true;
            bt(dx, dy, t+1, tmp_arr);
            tmp_arr[x][y] = false;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    int tmp;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            tmp = cin.get();
            if(tmp == ' ' || tmp == '\n') tmp = cin.get();
            arr[i][j] = tmp;
        }
    }
    tmp_arr[r-1][0] = true;
    bt(r-1,0,0,tmp_arr);
    cout << counts << '\n';

    return 0;
}