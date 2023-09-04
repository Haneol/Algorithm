#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int arr[100][100];
bool visited[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, depth = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            depth = depth < arr[i][j] ? arr[i][j] : depth;
        }

    int max = 0, count, x, y;
    queue<pair<int, int> > q;
    for(int d = depth; d >= 0; d--) {
        count = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] > d && !visited[i][j]) {
                    q.push({i, j});

                    while(!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();

                        if(!visited[x][y])
                            visited[x][y] = true;
                        else continue;

                        if(x > 0)
                            if(!visited[x-1][y] && arr[x-1][y] > d) q.push({x-1, y});
                        if(x < n - 1)
                            if(!visited[x+1][y] && arr[x+1][y] > d) q.push({x+1, y});
                        if(y > 0)
                            if(!visited[x][y-1] && arr[x][y-1] > d) q.push({x, y-1});
                        if(y < n - 1)
                            if(!visited[x][y+1] && arr[x][y+1] > d) q.push({x, y+1});
                    }

                    count++;
                }
            }
        }
        max = max < count ? count : max;
    }

    cout << max << '\n';

    return 0;
}