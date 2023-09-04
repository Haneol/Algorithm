#include<bits/stdc++.h>
using namespace std;

bool v_cmp(pair<int,int> a, pair<int,int> b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, deadline, cup_ramen;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        cin >> deadline >> cup_ramen;
        v.push_back({deadline, cup_ramen});
    }

    sort(v.begin(), v.end(), v_cmp);

    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

    for(int i = 0; i < n; i++) {
        if(pq.size() < v[i].first) pq.push(v[i]);
        else if(!pq.empty() && pq.top().second < v[i].second) {
            pq.pop();
            pq.push(v[i]);
        }
    }

    unsigned long long res = 0;
    while(!pq.empty()) {
        res += pq.top().second;
        pq.pop();
    }

    cout << res << '\n';

    return 0;
}