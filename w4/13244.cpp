#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

int main() {
    int T, n, m, a, b;
    cin >> T;

    queue<int> q;
    int x; 
    bool check, flag;

    while(T--) {
        cin >> n >> m;

        flag = false;

        for(int i = 0; i < m; i++) {
            cin >> a >> b;

            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }

        memset(visited, 0, sizeof(visited));

        q.push(1);
        visited[1] = true;
        while(!q.empty()) {
            x = q.front(); q.pop();

            check = false;
            for(int i = 0; i < graph[x].size(); i++) {
                if(visited[graph[x][i]]) {
                    if(!check) check = true;
                    else {
                        while(!q.empty()) q.pop();
                        cout << "graph" << '\n';
                        flag = true;
                        break;
                    }
                } else {
                    q.push(graph[x][i]);
                    visited[graph[x][i]] = true;
                }
            }

            if(!check && x != 1) {
                while(!q.empty()) q.pop();
                cout << "graph" << '\n';
                flag = true;
                break;
            }
        }

        for(int i = 1; i <= n; i++) graph[i].clear();

        if(flag) continue;
        else {
            for(int i = 1; i <= n; i++) {
                if(!visited[i]) {
                    cout << "graph" << '\n';
                    flag = true;
                    break;
                }
            }
            if(!flag) cout << "tree" << '\n';
        }
    }

    return 0;
}