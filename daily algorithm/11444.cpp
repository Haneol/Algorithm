#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

/*
    11444 피보나치 수 6
*/

void mult(long long *a, long long *b, long long *res) {
    long long tmp[] = {
        ((a[0] * b[0]) % MOD + (a[1] * b[2]) % MOD) % MOD,
        ((a[0] * b[1]) % MOD + (a[1] * b[3]) % MOD) % MOD,
        ((a[2] * b[0]) % MOD + (a[3] * b[2]) % MOD) % MOD,
        ((a[2] * b[1]) % MOD + (a[3] * b[3]) % MOD) % MOD
    };

    res[0] = tmp[0];
    res[1] = tmp[1];
    res[2] = tmp[2];
    res[3] = tmp[3];
}

void dnq(long long x, long long *res) {
    if(x <= 1) {
        res[0] = 1;
        res[1] = 1;
        res[2] = 1;
        res[3] = 0;
        return;
    }

    dnq(x / 2, res);
    mult(res, res, res);
    if(x % 2) {
        long long mat[] = {1,1,1,0};
        mult(res, mat, res);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;

    if(n < 2) {
        cout << n << '\n';
        return 0;
    }

    n--;

    long long res[] = {1,1,1,0};
    dnq(n, res);

    cout << res[0] % MOD << '\n';

    return 0;
}