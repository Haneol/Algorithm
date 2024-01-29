#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    vector<int> v, v2;
    while(true) {
        cin >> n;
        if(!n) break;

        v.clear();
        v2.clear();

        for(int i = 0; i < n; i++) {
            cin >> k;
            v.push_back(k);
            if(i < 6) v2.push_back(0);
            else v2.push_back(1);
        }

        sort(v.begin(), v.end());

        do {
            for(int i = 0; i < n; i++) {
                if(v2[i] == 0) {
                    cout << v[i] << ' ';
                }
            }
            cout << '\n';
        } while(next_permutation(v2.begin(), v2.end()));

        cout << '\n';
    }

    return 0;
}