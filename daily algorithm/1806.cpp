#include <bits/stdc++.h>

using namespace std;

/*
    1806 부분합
*/

int n, s;
int arr[100001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> s;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int start = 1, end = 1;
    int res = INT32_MAX;
    while(start <= n && end <= n) {
        if(arr[end] - arr[start-1] >= s) {
            res = min(res, end - start + 1);
            if(start == end) end++;
            start++;
        } else {
            end++;
        }
    }

    cout << (res == INT32_MAX ? 0 : res);

    return 0;
}