#include<bits/stdc++.h>
using namespace std;

int times[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, t1, t2;
    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        cin >> t1 >> t2;
        for(int j = t1; j < t2; j++) times[j]++;
    }

    int sum = 0;
    for(int i : times) {
        switch (i)
        {
        case 1:
            sum += A;
            break;
        case 2:
            sum += B*2;
            break;
        case 3:
            sum += C*3;
        default:
            break;
        }
    }

    cout << sum << '\n';

    return 0;
}