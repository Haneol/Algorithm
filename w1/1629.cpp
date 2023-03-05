#include<bits/stdc++.h>
using namespace std;

long long d = 0;

long long dnq(int a, int b, int c) {
    if(b == 1) return a % c;

    d = dnq(a, b/2, c);

    if(b % 2) return (d * d) % c * (a % c) % c;
    else return (d * d) % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << dnq(a,b,c) << '\n';

    return 0;
}