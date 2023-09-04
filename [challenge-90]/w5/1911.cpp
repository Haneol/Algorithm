#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,l;
    cin >> n >> l;

    vector<pair<int,int>> v;
    int s,e;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end());

    int pos = 0, res = 0;
    for(int i = 0; i < v.size(); i++) {
        s = max(v[i].first, pos);
        e = v[i].second;

        if(s >= e) continue;

        if((e - s) % l == 0) {
            res += (e - s) / l;
            pos = e + 1;
        } else {
            res += (e - s) / l + 1;
            pos = s + ((e - s) / l + 1) * l;
        }
    }

    cout << res << '\n';
    
    return 0;
}