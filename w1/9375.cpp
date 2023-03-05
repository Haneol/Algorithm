#include<bits/stdc++.h>
using namespace std;

map<string, int> type;
int dress[31] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, counts;
    string _type, _dress;

    cin >> T;

    while(T--)  {
        type.clear();
        memset(dress, 0, sizeof(dress));
        m = 0; counts = 1;
        cin >> n;

        if(n == 0) {
            cout << 0 << '\n'; continue;
        }

        for(int i = 0; i < n; i++) {
            cin >> _dress >> _type;
            
            if(type.count(_type) == 0) {
                type.insert({_type, m}); m++;
            }

            dress[type[_type]]++;
        }

        for(int i : dress) {
            counts *= i + 1;
        }

        cout << counts - 1 << '\n';
    }

    return 0;
}