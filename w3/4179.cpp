#include<bits/stdc++.h>
using namespace std;

char arr[1001][1001];
bool visited[1001][1001];
pair<int, int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c;
    cin >> r >> c;

    tuple<int, int, char> jihun;
    vector<tuple<int, int, char> > fire;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'J') {
                jihun = {i,j,'J'};
                arr[i][j] = '.';
            }
            else if(arr[i][j] == 'F') fire.push_back({i,j,'F'});
        }
    }

    queue<tuple<int, int, char> > q;
    for(auto t : fire) q.push(t);
    q.push(jihun);

    int x, y, type, dx, dy, size;
    int times = 0;
    bool flag = false;
    while(!q.empty()) {
        size = q.size();
        while(size--) {
            x = get<0>(q.front());
            y = get<1>(q.front());
            type = get<2>(q.front());
            q.pop();

            if(visited[x][y] && !(arr[x][y] == 'J' && type == 'F')) continue;
            visited[x][y] = true;
            arr[x][y] = type;
            if(type == 'J' && (x == 0 || y == 0 || x == r-1 || y == c-1)) {
                flag = true; break;
            }

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(!visited[dx][dy] && arr[dx][dy] == '.') q.push({dx, dy, type});
                else if(visited[dx][dy] && type == 'F' && arr[dx][dy] == 'J') q.push({dx, dy, type});
            }
            if(flag) break;
        }
        times++;

        if(flag) break;
    }

    if(flag) cout << times << '\n';
    else cout << "IMPOSSIBLE\n";
    

    return 0;
}