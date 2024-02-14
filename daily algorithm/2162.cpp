#include <bits/stdc++.h>

using namespace std;

/*
    2162 선분 그룹
*/

int n;
pair<pair<int,int>, pair<int,int>> v[3001];
int memo[3001];
int arr[3001];

int Find(int x) {
    if(memo[x] == x) return x;

    return Find(memo[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    memo[y] = x;
}

int ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    int tmp = (b.first - a.first)*(c.second - b.second) - (b.second - a.second)*(c.first - b.first);

    if(tmp > 0) return 1;
    else if(tmp < 0) return -1;
    else return 0;
}

bool isCross(int x, int y) {
    int ccw1 = ccw(v[x].first, v[x].second, v[y].first) * ccw(v[x].first, v[x].second, v[y].second);
    int ccw2 = ccw(v[y].first, v[y].second, v[x].first) * ccw(v[y].first, v[y].second, v[x].second);

    if(ccw1 <= 0 && ccw2 <= 0) {
        if(ccw1 == 0 && ccw2 == 0) {
            if(v[x].first > v[x].second) swap(v[x].first, v[x].second);
            if(v[y].first > v[y].second) swap(v[y].first, v[y].second);

            return v[x].first <= v[y].second && v[y].first <= v[x].second;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
    }

    if(n == 1) {
        cout << 1 << '\n' << 1;
        return 0;
    }

    for(int i = 1; i <= n; i++) memo[i] = i;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(isCross(i,j)) {
                Union(i+1, j+1);
            }
        }
    }

    for(int i = 1; i <= n; i++) arr[Find(i)]++;

    int cnt = 0, res = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i]) {
            res = max(res, arr[i]);
            cnt++;
        }
    }

    cout << cnt << '\n' << res;

    return 0;
}