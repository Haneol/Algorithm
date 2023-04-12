#include<bits/stdc++.h>
using namespace std;

int arr[4][4];
bool visited[4][4];
int n, m, k, res;

void dfs(int depth) {
    int sum;

    //row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
        }
    }

    //col
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    bool flag;
    for(int i = 0; i < n; i++) {
        flag = false;
        for(int j = 0; j < m; j++) {
            k = cin.get();
            if(k == ' ' || k == '\n') k = cin.get();
            if(k == '0' && !flag) arr[i][j] = -1;
            else {
                flag = true;
                arr[i][j] = k - '0';
            }
        }
    }
    
    int x = max(n,m);

    dfs(x);

    return 0;
}