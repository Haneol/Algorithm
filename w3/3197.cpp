#include<bits/stdc++.h>
using namespace std;

char arr[1501][1501];
bool visited[1501][1501][2];
pair<int, int> dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> wq, wbq;
    queue<tuple<int,int,int>> sq, sbq;

    int r, c, k = 1;
    char tmp;

    cin >> r >> c;
    for(int i = 0 ; i < r; i++) {
        for(int j = 0; j < c; j++) {
            do {cin.get(tmp);} while(tmp == ' ' || tmp == '\n');
            if(tmp == 'L') {
                sbq.push({i, j, k++});
                wbq.push({i, j});
            }
            else if(tmp == '.') wbq.push({i, j});
            arr[i][j] = tmp;
        }
    }

    int x, y, l, dx, dy, t = 0;
    while(!wbq.empty() || !sbq.empty()) {
        while(!wbq.empty()) { wq.push(wbq.front()); arr[get<0>(wbq.front())][get<1>(wbq.front())] = '.'; wbq.pop(); }
        while(!sbq.empty()) { sq.push(sbq.front()); sbq.pop(); }
        while(!wq.empty()) {
            tie(x,y) = wq.front(); wq.pop();

            if(visited[x][y][0]) continue;
            visited[x][y][0] = true;

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;

                if(!visited[dx][dy][0] && (arr[dx][dy] == '.' || arr[dx][dy] == 'L' )) wq.push({dx, dy});
                else if(!visited[dx][dy][0] && arr[dx][dy] == 'X') wbq.push({dx, dy});
            }
        }

        while(!sq.empty()) {
            tie(x,y,l) = sq.front(); sq.pop();

            if(visited[x][y][1]) continue;
            else {
                visited[x][y][1] = true;
                if(l == 1) arr[x][y] = '1';
                else arr[x][y] = '2';
            }

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;

                if(visited[dx][dy][1] && ((arr[x][y] == '1' && arr[dx][dy] == '2') || (arr[x][y] == '2' && arr[dx][dy] == '1'))) {
                    cout << t << '\n';
                    return 0;
                }

                if(!visited[dx][dy][1] && arr[dx][dy] == '.') {
                    sq.push({dx, dy, l});
                }
                else if(!visited[dx][dy][1] && arr[dx][dy] == 'X') {
                    sbq.push({dx, dy, l});
                }
            }
        }

        t++;
    }

    return 0;
}