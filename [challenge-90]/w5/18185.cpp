#include<bits/stdc++.h>
using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 0, x, y, z;
    for(int i = 0; i < n-2; i++) {
        x = i;
        y = i+1;
        z = i+2;
        while(arr[x]) {
            if(arr[y]) {
                if(arr[y] <= arr[z]) {
                    arr[x]--;
                    arr[y]--;
                    arr[z]--;
                    res += 7;
                } else {
                    arr[x]--;
                    arr[y]--;
                    res += 5;
                }
            } else {
                arr[x]--;
                res += 3;
            }
        }
    }

    while(arr[n-2]) {
        if(arr[n-1]) {
            arr[n-2]--;
            arr[n-1]--;
            res += 5;
        } else {
            arr[n-2]--;
            res += 3;
        }
    }

    while(arr[n-1]) {
        arr[n-1]--;
        res += 3;
    }

    cout << res << '\n';

    return 0;
}