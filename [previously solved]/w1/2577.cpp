#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    int arr[10] = {0,};

    cin >> a >> b >> c;

    a = a*b*c;

    while(a / 10) {
        arr[a%10]++;
        a /= 10;    
    }
    arr[a]++;

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }
}