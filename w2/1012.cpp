#include<bits/stdc++.h>
using namespace std;

int arr[52][52];
bool visited[52][52];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T,n,m,k,x,y,dx,dy,count;
    cin >> T;
    vector<pair<int, int> > v;
    queue<pair<int, int> > q;

    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        v.clear();
        cin >> m >> n >> k;
        while(k--) {
            cin >> x >> y;
            v.push_back({x+1,y+1});
            arr[x+1][y+1] = 1;
        }

        count = 0;
        for(pair<int, int> i : v) {
            if(visited[i.first][i.second]) continue;
            
            q.push(i);
            while(!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                if(!visited[x][y]) visited[x][y] = true;
                else continue;

                for(int j = 0; j < 4; j++) {
                    dx = x + dir[j].first;
                    dy = y + dir[j].second;

                    if(!visited[dx][dy] && arr[dx][dy] == 1) q.push({dx,dy});
                }
            }
            count++;
        }

        cout << count << '\n';
    }

    return 0;
}