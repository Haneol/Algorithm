#include<bits/stdc++.h>
using namespace std;

bool visited[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<pair<int, int> > q;
    q.push({n,0});
    visited[n] = true;

    int x, times, v_times = 0, cnt = 0;
    int dx[3];
    while(!q.empty()) {
        x = q.front().first;
        times = q.front().second;
        q.pop();

        visited[x] = true;

        if(x == k) {
            if(v_times == 0) {
                v_times = times;
                cnt++;
            } else if(v_times > 0 && times == v_times) {
                cnt++;
            }
        }

        dx[0] = x + 1;
        dx[1] = x - 1;
        dx[2] = x * 2;

        for(int d = 0; d < 3; d++) {
            if(dx[d] < 0 || dx[d] > 100000) continue;

            if(!visited[dx[d]]) q.push({dx[d], times + 1});
        }
    }

    cout << v_times << '\n';
    cout << cnt << '\n';

    return 0;
}