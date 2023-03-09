#include<bits/stdc++.h>
using namespace std;

int arr[10][10];
bool visited[8][8];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, count;
    cin >> n >> m;

    fill(&arr[0][0], &arr[9][9], 1);
    vector<pair<int, int> > virus;
    vector<pair<int, int> > empty;

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) virus.push_back({i, j});
            else if(arr[i][j] == 0) empty.push_back({i, j});
            else count++;
        }

    count *= -1;

    queue<pair<int, int> > q;
    int x, y, dx, dy, max = -1;
    for(int i = 0; i < empty.size() - 2; i++) {
        for(int j = i + 1; j < empty.size() - 1; j++) {
            for(int k = j + 1; k < empty.size(); k++) {
                fill(&visited[0][0], &visited[7][7], false);
                for(auto v : virus) q.push(v);
                while(!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;

                    if(!visited[x][y]) visited[x][y] = true;
                    else continue;

                    for(int d = 0; d < 4; d++) {
                        dx = d + dir[d].first;
                        dy = d + dir[d].second;

                        if(!visited[dx][dy] && arr[dx][dy] == 0 
                            && dx != empty[i].first && dy != empty[i].second
                            && dx != empty[j].first && dy != empty[j].second
                            && dx != empty[k].first && dy != empty[k].second
                            ) q.push({dx, dy});
                    }
                }
                for(int a = 0; a < n; a++)
                    for(int b = 0; b < m; b++)
                        if(!visited[a][b]) count++;
                max = max > count ? max : count;
            }
        }
    }

    cout << max << '\n';



    return 0;
}