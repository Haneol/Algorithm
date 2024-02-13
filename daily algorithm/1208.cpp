#include <bits/stdc++.h>
#define MAX 4000000

using namespace std;

/*
    1208 부분수열의 합 2
*/

int n, s;
int arr[40];
int first[1 << 20];
int second[1 << 20];
int val[MAX * 2 + 1];

int find(int x, int start, int end) {
    if(start > end) return 0;

    int k = (start + end) / 2;
    
    if(second[k] == x) {
        return val[second[k] + MAX];
    } else if (second[k] > x) {
        return find(x, start, k-1);
    } else {
        return find(x, k+1, end);
    }
}

long long solve() {
    int n1 = n / 2;
    int n2 = n - n1;

    int sum;
    for(int i = 0; i < (1 << n1); i++) {
        sum = 0;
        for(int j = 0; j < n1; j++) {
            if(i & (1 << j)) {
                sum += arr[n1 - j - 1];
            }
        }
        first[i] = sum;
    }

    for(int i = 0; i < (1 << n2); i++) {
        sum = 0;
        for(int j = 0; j < n2; j++) {
            if(i & (1 << j)) {
                sum += arr[n - j - 1];
            }
        }
        second[i] = sum;
        val[sum + MAX]++;
    }

    sort(first, first + (1 << n1));
    sort(second, second + (1 << n2));

    long long cnt = 0;
    for(int i = 0; i < (1 << n1); i++) {
        cnt += (long long) find(s - first[i], 0, (1 << n2) - 1);
    }

    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long res = solve();
    cout << ((s == 0) ? res - 1 : res);

    return 0;
}
