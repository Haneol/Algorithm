// 나중에 다시 풀어보기

#include<bits/stdc++.h>
using namespace std;

int arr[1002][1002];
int times_arr[1002][1002];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    fill(&arr[0][0], &arr[1001][1001], -1);

    pair<int, int> virus1, virus2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) virus1 = {i, j};
            else if(arr[i][j] == 2) virus2 = {i, j};
        }
    }

    // x, y, virus_type
    queue<tuple<int, int, int> > q;
    q.push({virus1.first, virus1.second, 1});
    q.push({virus2.first, virus2.second, 2});
    times_arr[virus1.first][virus1.second] = 1;
    times_arr[virus2.first][virus2.second] = 1;

    int bundle, times = 2;
    int x, y, dx, dy, type;
    int num1 = 0, num2 = 0, num3 = 0;

    while(!q.empty()) {
        bundle = q.size();
        while(bundle--) {
            x = get<0>(q.front());
            y = get<1>(q.front());
            type = get<2>(q.front());
            q.pop();

            if(times_arr[x][y] >= times || arr[x][y] == 3) continue;

            for(int d = 0; d < 4; d++) {
                dx = x + dir[d].first;
                dy = y + dir[d].second;

                if(times_arr[dx][dy] < times && arr[dx][dy] == 0) {
                    times_arr[dx][dy] = times;
                    arr[dx][dy] = type;
                    q.push({dx, dy, type});
                } else if(times_arr[dx][dy] == times && (arr[dx][dy] == 1 || arr[dx][dy] == 2) && arr[dx][dy] != type) {
                    arr[dx][dy] = 3;
                }
            }
        }
        times++;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] == 1) num1++;
            else if(arr[i][j] == 2) num2++;
            else if(arr[i][j] == 3) num3++;
        }

    cout << num1 << ' ' << num2 << ' ' << num3 << '\n';

    return 0;
}