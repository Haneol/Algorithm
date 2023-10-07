#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, x;
    int student[100001];
    int visited[100001];

    cin >> T;

    while(T--) {
        cin >> n;

        fill(&visited[0], &visited[n+1], 0);
        for(int i = 1; i <= n; i++) cin >> student[i];

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue;

            x = i;
            while(true) {
                visited[x] = i;
                x = student[x];
                if(visited[x] == i) {
                    while(visited[x] != -1) {
                        visited[x] = -1;
                        x = student[x];
                    }
                    break;
                } else if (visited[x] != 0) break;
            }
        }

        for(int i = 1; i <= n; i++) visited[i] != -1 ? cnt++ : cnt;
        cout << cnt << '\n';
    }

    return 0;
}