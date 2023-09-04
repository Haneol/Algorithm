#include<bits/stdc++.h>
using namespace std;

int arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];

    cin >> x;

    sort(arr, arr + n);

    int l = 0, r = n-1, res = 0;
    while(l < r) {
        if(arr[l] + arr[r] == x) {
            res++;
            l++; r--;
        } else if(arr[l] + arr[r] > x) {
            r--;
        } else {
            l++;
        }
    }

    cout << res << '\n';

    return 0;
}