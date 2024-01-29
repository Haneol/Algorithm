#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
bool visited[2][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v, x, y;
    stack<int> s;
    queue<int> q;

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    s.push(v);
    q.push(v);
    visited[1][v] = true;

    while(!s.empty()) {
        x = s.top(), s.pop();

        if(!visited[0][x]) {
            cout << x << ' ';
            visited[0][x] = true;
        }

        for(int k = graph[x].size() - 1; k >= 0; k--) {
            if(!visited[0][graph[x][k]]) {
                s.push(graph[x][k]);
            }
        }
    }

    cout << '\n';
    while(!q.empty()) {
        x = q.front(), q.pop();

        cout << x << ' ';

        for(int k : graph[x]) {
            if(!visited[1][k]) {
                visited[1][k] = true;
                q.push(k);
            }
        }
    }

    return 0;
}