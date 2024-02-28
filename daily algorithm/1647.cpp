#include <bits/stdc++.h>

using namespace std;

/*
    1647 도시 분할 계획

    최소 스패닝 트리
    경로 압축 최적화
*/

int n, m, a, b, c;
vector<tuple<int, int, int>> cost;
int memo[100001];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) < get<2>(b);
}

int Find(int x) {
    if(memo[x] == x) return x;

    return memo[x] = Find(memo[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    memo[y] = x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cost.push_back({a,b,c});
    }

    for(int i = 1; i <= n; i++) memo[i] = i;
    sort(cost.begin(), cost.end(), cmp);

    int res = 0, k = 0;
    for(int i = 0; k < n-2; i++) {
        tie(a,b,c) = cost[i];
        if(Find(a) != Find(b)) {
            res += c;
            k++;
            Union(a,b);
        }
    }

    cout << res;

    return 0;
}