#include<bits/stdc++.h>
using namespace std;

#define MAX 10001

int sum[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b,tmp;
    cin >> a >> b;

    int last = MAX-1;
    bool carry = false;

    if(a.size() > b.size()) {
        tmp = a;
        a = b;
        b = tmp;
    }

    for(int i = a.size() - 1; i >= 0; i--) sum[last--] = a[i] - '0';

    last = MAX-1;
    for(int i = b.size() - 1; i >= 0; i--, last--) {
        if(carry) {
            if(sum[last] + b[i] - '0' + 1 > 9) carry = true;
            else carry = false;
            sum[last] = (sum[last] + b[i] - '0' + 1) % 10;
        } else {
            if(sum[last] + b[i] - '0' > 9) carry = true;
            else carry = false;
            sum[last] = (sum[last] + b[i] - '0') % 10;
        }
    }
    if(carry) sum[last--] = 1;

    for(int i = last + 1; i < MAX; i++) cout << (char) (sum[i] + '0');
    cout << '\n';

    return 0;
}