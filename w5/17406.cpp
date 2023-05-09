#include<bits/stdc++.h>
using namespace std;

int res = INT32_MAX;
int n,m,k;
vector<tuple<int,int,int>> v;

int calcul(int arr[][51]) {
    int min_sum = INT32_MAX, sum;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        min_sum = min(min_sum, sum);
    }
    return min_sum;
}

void rotate(int x[][51], int r, int c, int s) {
    int tmp;
    for(int i = 1; i <= s; i++) {
        tmp = x[r-i][c+i];
        for(int j = c+i; j > c-i; j--) x[r-i][j] = x[r-i][j-1];
        for(int j = r-i; j < r+i; j++) x[j][c-i] = x[j+1][c-i];
        for(int j = c-i; j < c+i; j++) x[r+i][j] = x[r+i][j+1];
        for(int j = r+i; j > r-i+1; j--) x[j][c+i] = x[j-1][c+i];
        x[r-i+1][c+i] = tmp;
    }
}

void dfs(int arr[][51], bool visited[], int depth) {
    if(depth == k) {
        res = min(res, calcul(arr));
        return;
    }

    int new_arr[51][51];
    for(int i = 0; i < k; i++) {
        if(visited[i]) continue;

        copy(&arr[0][0], &arr[0][0]+51*51, &new_arr[0][0]);
        rotate(new_arr, get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
        
        visited[i] = true;
        dfs(new_arr, visited, depth+1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    int arr[51][51];
    bool visited[7] = {false,};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int r,c,s;
    for(int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        v.push_back({r-1,c-1,s});
    }

    dfs(arr, visited, 0);

    cout << res << '\n';

    return 0;
}