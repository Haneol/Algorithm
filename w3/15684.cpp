#include<bits/stdc++.h>
using namespace std;

int n, m, h;
bool arr[12][32];

bool check_vaild() {
    int x;
    for(int i = 1; i <= n; i++) {
        x = i;
        for(int j = 1; j <= h; j++) {
            if(i < n && arr[i][j]) {
                i++;
            } else if(i > 1 && arr[i-1][j]) {
                i--;
            }
        }
        if(x != i) return false;
    }

    return true;
}

int res = -1;
int bt(int depth, int x) {
    if(depth > 3) return -1;
    if(check_vaild()) return depth;

    int tmp;
    for(int i = x; i < n; i++) {
        for(int j = 1; j <= h; j++) {
            if(arr[i][j] || (i < n-1 && arr[i+1][j])) continue;
            arr[i][j] = true;
            tmp = bt(depth+1, i);
            if(res == -1 || (res > tmp && tmp != -1)) res = tmp;
            arr[i][j] = false;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    int a,b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b][a] = true;
    }

    cout << bt(0,1) << '\n';

    return 0;
}