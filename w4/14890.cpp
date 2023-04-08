#include<bits/stdc++.h>
using namespace std;

int arr[101][101];
int dist[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int x, slope, res = 0;
    bool flag;
    for(int i = 0; i < n; i++) {
        x = 0; slope = 0; flag = true;
        memset(dist, 0, sizeof(dist));
        for(int j = 0; j < n; j++) {
            if(x == 0) {
                x = arr[i][j];
                dist[j] = 1;
            } else if(x == arr[i][j]) {
                if(slope) { slope--; dist[j] = 1; }
                else dist[j] = dist[j-1] + 1;
                x = arr[i][j];
            } else if(x == arr[i][j] + 1) { // down
                if(slope > 1) {
                    flag = false;
                    break;
                }
                slope = l;
                dist[j] = 1;
                x = arr[i][j];
            } else if(x == arr[i][j] - 1) { // up
                if(dist[j-1] < l || slope) {
                    flag = false;
                    break;
                }
                dist[j] = 1;
                x = arr[i][j];
            } else {
                flag = false;
                break;
            }
        }

        if(flag && slope <= 1) res++;

        x = 0; slope = 0; flag = true;
        memset(dist, 0, sizeof(dist));
        for(int j = 0; j < n; j++) {
            if(x == 0) {
                x = arr[j][i];
                dist[j] = 1;
            } else if(x == arr[j][i]) {
                if(slope) { slope--; dist[j] = 1; }       
                else dist[j] = dist[j-1] + 1;
                x = arr[j][i];
            } else if(x == arr[j][i] + 1) { // down
                if(slope > 1) {
                    flag = false;
                    break;
                }
                slope = l;
                dist[j] = 1;
                x = arr[j][i];
            } else if(x == arr[j][i] - 1) { // up
                if(dist[j-1] < l || slope) {
                    flag = false;
                    break;
                }
                dist[j] = 1;
                x = arr[j][i];
            } else {
                flag = false;
                break;
            }
        }

        if(flag && slope <= 1) res++;
    }

    cout << res << '\n';

    return 0;
}