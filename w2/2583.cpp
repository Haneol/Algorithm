#include<bits/stdc++.h>
using namespace std;

int arr[102][102];
bool visited[102][102];
pair<int, int> dir[4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    fill(&arr[0][0], &arr[101][101], 1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            arr[i][j] = 0;

    int x1, x2, y1, y2;
    for(int i = 0; i < k; i++) {
        cin >> y1 >> x1 >> y2 >> x2;

        for(int x = x1; x < x2; x++)
            for(int y = y1; y < y2; y++)
                arr[x+1][y+1] = 1;
    }

    queue<pair<int, int> > q;
    int countNum = 0, tmp;
    vector<int> countArea;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(visited[i][j] || arr[i][j]) continue;

            q.push({i, j});
            tmp = 0;
            while(!q.empty()) {
                x1 = q.front().first;
                y1 = q.front().second;
                q.pop();

                if(visited[x1][y1]) continue;
                visited[x1][y1] = true; tmp++;

                for(int d = 0; d < 4; d++) {
                    x2 = x1 + dir[d].first;
                    y2 = y1 + dir[d].second;

                    if(!visited[x2][y2] && !arr[x2][y2]) q.push({x2, y2});

                }
            }
            countNum++;
            countArea.push_back(tmp);
        }
    }

    sort(countArea.begin(), countArea.end());
    cout << countNum << '\n';
    for(int i = 0; i < countArea.size(); i++) {
        cout << countArea[i];
        i == countArea.size() - 1 ? cout << '\n' : cout << ' ';
    }

    return 0;
}