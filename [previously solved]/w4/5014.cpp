#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int visited[MAX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F,S,G,U,D;
    cin >> F >> S >> G >> U >> D;

    if(S == G) {
        cout << 0 << '\n';
        return 0;
    }

    int y, dy;
    queue<int> q;
    q.push(S);
    visited[S] = 1;
    while(!q.empty()) {
        y = q.front(); q.pop();

        dy = y + U;
        if(dy >= 1 && dy <= F && !visited[dy]) {
            if(dy == G) {
                cout << visited[y] << '\n';
                return 0;
            }
            q.push(dy);
            visited[dy] = visited[y] + 1;
        }

        dy = y - D;
        if(dy >= 1 && dy <= F && !visited[dy]) {
            if(dy == G) {
                cout << visited[y] << '\n';
                return 0;
            }
            q.push(dy);
            visited[dy] = visited[y] + 1;
        }
    }

    cout << "use the stairs" << '\n';

    return 0;
}