#include<bits/stdc++.h>
using namespace std;

int times[100001];
int counts[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);

    int x;
    int dx[3];
    while(!q.empty()) {
        x = q.front();
        q.pop();

        dx[0] = x + 1;
        dx[1] = x - 1;
        dx[2] = x * 2;

        for(int d = 0; d < 3; d++) {
            if(dx[d] < 0 || dx[d] > 100000) continue;

            if(counts[dx[d]] == 0) {
                counts[dx[d]] = counts[x] == 0 ? 1 : counts[x];
                times[dx[d]] = times[x] + 1;
                q.push(dx[d]);
            } else if(times[dx[d]] > times[x]) {
                times[dx[d]] = times[x] + 1;
                counts[dx[d]]++;
            }
        }
    }

    // for(int t = 0; t <= k * 2; t++) {
    //     cout << times[t] << ' ';
    // }
    // cout << '\n';
    // for(int t = 0; t <= k * 2; t++) {
    //     cout << counts[t] << ' ';
    // }
    // cout << '\n';

    cout << times[k] << ' ' << counts[k] << '\n';

    return 0;
}