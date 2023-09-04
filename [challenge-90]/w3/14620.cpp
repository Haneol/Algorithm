#include<bits/stdc++.h>
using namespace std;

int n, output = INT32_MAX;
int arr[10][10];
bool visited[10][10];

void bt(int depth, int cost) {
    if(depth == 3) {
        output = min(output, cost);
        return;
    }

    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(visited[i][j] || visited[i+1][j] || visited[i][j+1] || visited[i-1][j] || visited[i][j-1]) continue;

            visited[i][j] = true; visited[i+1][j] = true; visited[i][j+1] = true; visited[i-1][j] = true;  visited[i][j-1] = true;
            bt(depth + 1, cost + arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i-1][j] + arr[i][j-1]);
            visited[i][j] = false; visited[i+1][j] = false; visited[i][j+1] = false; visited[i-1][j] = false;  visited[i][j-1] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    bt(0, 0);
    cout << output << '\n';

    return 0;
}