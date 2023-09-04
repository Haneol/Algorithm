#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> v;

    int t,t2;
    for(int i = 0; i < n; i++) {
        cin >> t >> t2;
        v.push_back({t, t2}); 
    }

    sort(v.begin(), v.end(), cmp);

    int res = 0;
    for(auto i : v) {
        if(i.first < res){
            res += i.second;
        } else {
            res = i.first + i.second;
        }
    }

    cout << res << '\n';

    return 0;
}