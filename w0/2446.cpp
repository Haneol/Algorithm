#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n;
    m = 2*n-1;

    for(int i = 0; i < m; i++) {
        k = n - abs(n-i-1) - 1;
        for(int j = 0; j < m; j++) {
            if(k > j) {
                cout << ' ';
            } else if(m-k > j) {
                cout << '*';
            }
        }
        cout <<'\n';
    }
}