#include<bits/stdc++.h>
using namespace std;

vector<int> trusted[10000];
bool visited[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, com1, com2;

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> com1 >> com2;
        trusted[com2-1].emplace_back(com1-1);
    }

    int now, count;
    queue<int> q;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        count = 0;
        memset(visited, false, sizeof(visited));
        q.push(i);
        while(!q.empty()) {
            now = q.front(); q.pop();

            if(visited[now]) continue;
            visited[now] = true; count++;
            
            for(int tmp : trusted[now]) {
                if(!visited[tmp]) q.push(tmp);
            }
        }
        if(v.empty()) v.push_back({i, count});
        else if(v[0].second < count) { v.clear(); v.push_back({i, count}); }
        else if(v[0].second == count) v.push_back({i, count});
    }

    sort(v.begin(), v.end());

    for(auto i : v)
        cout << i.first + 1 << ' ';
    cout << '\n';

    return 0;
}