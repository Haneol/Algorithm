#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int val, times = 0;
    n++;
    while(n--) {
        val = n;
        while(val % 5 == 0 && val > 1) {
            val /= 5;
            times++;
        }
    }

    cout << times << '\n';

    return 0;
}