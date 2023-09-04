#include<bits/stdc++.h>
using namespace std;

int res;

int promising(int arr[][20], int &n, int d) {
    int val = 0;
    int p;
    if(d == 0) {    // up
        for(int j = 0; j < n; j++) {
            for(int i = 1; i < n; i++) {
                p = i;
                while(p < n && arr[p][j] == 0) p++;
                if(p >= n) break;

                if(arr[i-1][j] == arr[p][j]) {
                    arr[i-1][j] += arr[p][j];
                    arr[p][j] = 0;
                    val = max(val, arr[i-1][j]);
                }
            }
            p = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i][j] != 0) {
                    if(p != i) {
                        arr[p][j] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    p++;
                }
            }
        }
    } else if(d == 1) { //down
        for(int j = 0; j < n; j++) {
            for(int i = n-2; i >= 0; i--) {
                p = i;
                while(p >= 0 && arr[p][j] == 0) p--;
                if(p < 0) break;

                if(arr[i+1][j] == arr[p][j]) {
                    arr[i+1][j] += arr[p][j];
                    arr[p][j] = 0;
                    val = max(val, arr[i+1][j]);
                }
            }
            p = n-1;
            for(int i = n-1; i >= 0; i--) {
                if(arr[i][j] != 0) {
                    if(p != i) {
                        arr[p][j] = arr[i][j];
                        arr[i][j] = 0;
                    }
                    p--;
                }
            }
        }
    } else if(d == 2) { // left
        for(int j = 0; j < n; j++) {
            for(int i = 1; i < n; i++) {
                p = i;
                while(p < n && arr[j][p] == 0) p++;
                if(p >= n) break;

                if(arr[j][i-1] == arr[j][p]) {
                    arr[j][i-1] += arr[j][p];
                    arr[j][p] = 0;
                    val = max(val, arr[j][i-1]);
                }
            }
            p = 0;
            for(int i = 0; i < n; i++) {
                if(arr[j][i] != 0) {
                    if(p != i) {
                        arr[j][p] = arr[j][i];
                        arr[j][i] = 0;
                    }
                    p++;
                }
            }
        }
    } else if(d == 3) { // right
         for(int j = 0; j < n; j++) {
            for(int i = n-2; i >= 0; i--) {
                p = i;
                while(p >= 0 && arr[j][p] == 0) p--;
                if(p < 0) break;

                if(arr[j][i+1] == arr[j][p]) {
                    arr[j][i+1] += arr[j][p];
                    arr[j][p] = 0;
                    val = max(val, arr[j][i+1]);
                }
            }
            p = n-1;
            for(int i = n-1; i >= 0; i--) {
                if(arr[j][i] != 0) {
                    if(p != i) {
                        arr[j][p] = arr[j][i];
                        arr[j][i] = 0;
                    }
                    p--;
                }
            }
        }
    }

    return val;
}

void bt(int arr[][20], int &n, int depth) {
    if(depth >= 5) return;

    for(int i = 0; i < 4; i++) {
        int next[20][20];
        copy(&arr[0][0], &arr[0][0] + 400, &next[0][0]);
        res = max(res, promising(next, n, i));
        bt(next, n, depth+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[20][20];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            res = max(res, arr[i][j]);
        }
    }

    bt(arr, n, 0);

    cout << res << '\n';

    return 0;
}