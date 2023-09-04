#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v[9];
    int sum = 0;

    for(int i = 0; i < 9; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sum -= 100;
    sort(v, v + 9);

    int i, j;
    bool b;
    for(i = 0; i < 8; i++) {
        for(j = i + 1; j < 9; j++) {
            if(v[i] + v[j] == sum) goto quit;
        }
    }

quit:

    for(int k = 0; k < 9; k++) {
        if(k == i || k == j) continue;

        cout << v[k] << '\n';
    }

    return 0;
}