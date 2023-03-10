#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i = 666, tmp, check;
    bool flag;
    while(n--) {
        flag = true;
        while(flag) {
            tmp = i;
            check = 0;
            do {
                if(tmp % 10 == 6) check++;
                else check = 0;

                if(check == 3) {
                    flag = false;
                    break;
                }
            } while(tmp /= 10);
            i++;
        }
    }

    cout << i - 1 << '\n';

    return 0;
}