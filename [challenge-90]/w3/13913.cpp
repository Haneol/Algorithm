#include<bits/stdc++.h>
using namespace std;

int visited[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;

    cin >> n >> k;
    
    queue<pair<int, int>> q;
    q.push({n,0});

    fill(&visited[0], &visited[100001], -1);

    int x, t, dx[3];
    while(!q.empty()) {
        tie(x, t) = q.front();
        q.pop();

        if(x == k) break;

        dx[0] = x-1;
        dx[1] = x+1;
        dx[2] = x*2;

        for(int d = 0; d < 3; d++) {
            if(dx[d] < 0 || dx[d] > 100000) continue;

            if(visited[dx[d]] == -1) {
                visited[dx[d]] = x;
                q.push({dx[d], t+1});
            }
        }
    }

    cout << t << '\n';
    int tmp = k;
    stack<int> s;
    while(tmp != n) {
        s.push(tmp);
        tmp = visited[tmp];
    }
    s.push(n);
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';

    return 0;
}