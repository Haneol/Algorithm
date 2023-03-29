#include<bits/stdc++.h>
using namespace std;

int r, c, output;
char arr[21][21];
bool visited[26];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

void bt(int x, int y, int t) {
    output = max(output, t);

    int dx, dy;
    for(int d = 0; d < 4; d++) {
        dx = x + dir[d].first;
        dy = y + dir[d].second;

        if(dx < 0 || dy < 0 ||  dx >= r || dy >= c) continue;

        if(!visited[arr[dx][dy] - 'A']) {
            visited[arr[dx][dy] - 'A'] = true;
            bt(dx, dy, t+1);
            visited[arr[dx][dy] - 'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = true;
    bt(0,0,1);
    cout << output << '\n';

    return 0;
}