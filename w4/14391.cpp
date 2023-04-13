#include<bits/stdc++.h>
using namespace std;

int arr[4][4];
int n, m, k, res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            k = cin.get();
            if(k == ' ' || k == '\n') k = cin.get();
            arr[i][j] = k - '0';
        }
    }
    
    int bit_mask = 0, end = pow(2, n*m), sum, tmp;
    while(bit_mask < end) {
        sum = 0;
        for(int i = 0; i < n; i++) {
            tmp = 0;
            for(int j = 0; j < m; j++) {
                if(!(bit_mask & (1 << (i*m+j)))) {
                    tmp = tmp * 10 + arr[i][j];
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        for(int i = 0; i < m; i++) {
            tmp = 0;
            for(int j = 0; j < n; j++) {
                if(bit_mask & (1 << (j*m+i))) {
                    tmp = tmp * 10 + arr[j][i];
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        res = max(res, sum);
        bit_mask++;
    }

    cout << res << '\n';

    return 0;
}