#include<bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int> > v;

bool comp(tuple<int, int, int> i, tuple<int, int, int> j) { return get<1>(i) == get<1>(j) ? get<2>(i) < get<2>(j) : get<1>(i) > get<1>(j); }

int isContain(int k) { 
    for(int i = 0; i < v.size(); i++)
        if(get<0>(v[i]) == k) return i;

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, tmp, loc;
    cin >> n >> c;

    for(int i = 0; i < n; i++) {
        cin >> tmp;
        loc = isContain(tmp);
        if(loc == -1) v.push_back({tmp, 1, i});
        else get<1>(v[loc])++;
    }

    sort(v.begin(), v.end(), comp);

    for(auto i : v) {
        for(int j = 0; j < get<1>(i); j++) cout << get<0>(i) << ' ';
    }

    return 0;
}