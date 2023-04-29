#include<bits/stdc++.h>
using namespace std;

bool cmp2(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m1,m2;
    cin >> n >> k;

    vector<pair<int,int>> m;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        cin >> m1 >> m2;
        m.push_back({m1, m2});
    }

    for(int i = 0; i < k; i++) {
        cin >> m1;
        v.emplace_back(m1);
    }

    sort(m.begin(), m.end(), cmp2);
    sort(v.begin(), v.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    long long res = 0;
    int j = 0;
    for(int i = 0; i < k; i++) {
        while(j < n && m[j].first <= v[i]) {
            pq.push(m[j]); j++;
        }

        if(!pq.empty()) {
            res += pq.top().second;
            pq.pop();
        }
    }

    cout << res << '\n';

    return 0;
}