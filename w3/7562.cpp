#include <bits/stdc++.h>

using namespace std;

bool chess[304][304];
pair<int, int> dir[8] = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, l, x, y, dx, dy, nx, ny;
    queue<pair<int, int>> q;

    cin >> T;
    while(T--) {
        cin >> l >> x >> y >> nx >> ny;

        if(x == nx && y == ny) {
            cout << "0\n";
            continue;
        }

        while(!q.empty()) q.pop();
        fill(&chess[0][0], &chess[303][303], false);
        
        for(int i = 2; i <= l+1; i++)
            for(int j = 2; j <= l+1; j++)
                chess[i][j] = true;

        q.push({x+2,y+2});
        chess[x+2][y+2] = false;
        nx+=2; ny+=2;

        int size, cnt = 0;
        bool flag = false;
        while(!q.empty()) {
            size = q.size();
            while(size--) {
                tie(x,y) = q.front(); q.pop();

                for(int d = 0; d < 8; d++) {
                    dx = x + dir[d].first;
                    dy = y + dir[d].second;

                    if(chess[dx][dy]) {
                        if(dx == nx && dy == ny) {
                            flag = true;
                            break;
                        }

                        q.push({dx,dy});
                        chess[dx][dy] = false;
                    }
                }
            }
            cnt++;
            if(flag) break;
        }
        if(!flag) cout << "0\n";
        else cout << cnt << '\n';
    }

    return 0;
}