#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first == b.first ? (a.second > b.second) : (a.first < b.first);
}

struct cmp2 {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, p;
    cin >> n;

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end(), cmp);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> q;
    for(int i = 0; i < n; i++) {
        if(q.size() < v[i].first) {
            q.push(v[i]);
        } else if(q.top().second < v[i].second) {
            q.pop();
            q.push(v[i]);
        }
    }

    int res = 0;
    while(!q.empty()) {
        res += q.top().second;
        q.pop();
    }

    cout << res << '\n';

    return 0;
}