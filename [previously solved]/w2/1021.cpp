#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    deque<int> q;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) q.push_back(i);

    int output = 0, cnt;
    while(m--) {
        cin >> k;

        cnt = 0;
        while(q.front() != k) {
            q.push_back(q.front());
            q.pop_front();
            cnt++;
        }

        output += min(cnt, (int) q.size() - cnt);
        q.pop_front();
    }

    cout << output << '\n';

    return 0;
}