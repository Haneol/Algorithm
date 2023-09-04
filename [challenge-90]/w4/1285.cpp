#include<bits/stdc++.h>
using namespace std;

int arr[20][20];
int tmp_arr[20][20];
bool visited[401];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char tmp;
    int s_bit = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 'H') arr[i][j] = 0;
            else if(tmp == 'T') arr[i][j] = 1;
        }
    }

    int bit_mask = 0;
    int sum = INT32_MAX, tmp_sum, tmp_col;
    for(int i = 0; i < pow(2,n); i++) {
        // 3 -> 011
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                tmp_arr[j][k] = bit_mask & (1 << j) ? !arr[j][k] : arr[j][k];
            }
        }

        tmp_sum = 0;
        for(int j = 0; j < n; j++) {
            tmp_col = 0;
            for(int k = 0; k < n; k++) {
                if(tmp_arr[k][j]) tmp_col++;
            }
            tmp_sum += min(tmp_col, n-tmp_col);
        }
        sum = min(sum, tmp_sum);

        bit_mask++;
    }

    cout << sum << '\n';

    return 0;
}