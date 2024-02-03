#include <bits/stdc++.h>

using namespace std;

/*
    1043 거짓말
*/

int n, m, k, x, y, z, res;
int known[51];
vector<int> group[51];
bool flag;

int Find(int a) {
    if(known[a] == a) {
        return a;
    } else {
        return Find(known[a]);
    }
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    known[b] = a;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        known[i] = i;
    }

    for(int i = 0; i < k; i++) {
        cin >> x;
        known[x] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> x;

        for(int j = 0; j < x; j++) {
            cin >> y;
            group[i].push_back(y);
            
            if(j > 0) {
                if(Find(z) != 0) {
                    Union(y, z);
                } else {
                    Union(z, y);
                }
            } else if(j == 0) {
                z = y;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        flag = false;
        for(auto j : group[i]) {
            if(Find(j) == 0) {
                flag = true;
                break;
            }
        }
        if(!flag) res++;
    }

    cout << res << '\n';

    return 0;
}