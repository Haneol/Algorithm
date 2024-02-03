#include <bits/stdc++.h>

using namespace std;

/*
    1167 트리의 지름
*/

int v, x, y, d, res;
vector<pair<int, int>> tree[100001];
stack<pair<int, int>> s;
bool visited[100001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> v;

    for(int i = 1; i <= v; i++) {
        cin >> x;
        while(true) {
            cin >> y;
            if(y == -1) break;
            cin >> d;

            tree[x].push_back({y,d});
        }
    }

    s.push({1, 0});
    visited[1] = true;
    y = 1;
    while(!s.empty()) {
        tie(x, d) = s.top();
        s.pop();

        for(auto a : tree[x]) {
            if(!visited[a.first]) {
                s.push({a.first, d + a.second});
                if(res < d + a.second) {  
                    res = d + a.second;
                    y = a.first;
                }
                visited[a.first] = true;
            }
        }
    }

    fill(visited, visited + v + 1, false);

    s.push({y, 0});
    visited[y] = true;
    res = 0;
    while(!s.empty()) {
        tie(x, d) = s.top();
        s.pop();

        for(auto a : tree[x]) {
            if(!visited[a.first]) {
                s.push({a.first, d + a.second});
                res = max(res, d + a.second);
                visited[a.first] = true;
            }
        }
    }

    cout << res << '\n';

    return 0;
}