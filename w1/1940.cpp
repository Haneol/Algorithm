#include<bits/stdc++.h>
using namespace std;

int arr[15001] = {0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, rest, start, end, mid;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int result = 0;
    for(int i = 0; i < n; i++) {
        rest = m - arr[i];
        start = i + 1; end = n - 1;
        while(true) {
            if(start > end) break;
            mid = (start + end) /2;

            if(arr[mid] == rest) { result++; break; }
            else if(arr[mid] > rest) end = mid - 1;
            else start = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}