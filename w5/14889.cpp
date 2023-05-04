#include<bits/stdc++.h>
using namespace std;

int arr[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<int> v(n);
    int sum[2], res = INT32_MAX;
    for(int i = n/2; i < n; i++) v[i] = 1;
    do {
        sum[0] = 0; sum[1] = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(v[i] == v[j]) 
                    sum[v[i]] += (arr[i][j] + arr[j][i]);
        
        res = min(res, abs(sum[0] - sum[1]));
    } while(next_permutation(v.begin(), v.end()));

    cout << res << '\n';

    return 0;
}