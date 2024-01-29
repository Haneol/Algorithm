#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[10] = {0,};
    cin >> n;

    arr[n % 10]++;
    while(n /= 10) {
        arr[n % 10]++;
    }

    arr[6] = ceil((float) (arr[6] + arr[9]) / 2.0);
    arr[9] = 0;

    int max = 0;
    for(int i = 0; i < 10; i++) {
        max = arr[i] > max ? arr[i] : max;
    }

    cout << max;
}