#include<bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
vector<tuple<int, int, int, int, int>> v;
bool visited[16];

tuple<int, int, int, int, int> operator+(tuple<int, int, int, int, int> &t1, tuple<int, int, int, int, int> &t2) {
    return {get<0>(t1) + get<0>(t2), get<1>(t1) + get<1>(t2), get<2>(t1) + get<2>(t2), get<3>(t1) + get<3>(t2), get<4>(t1) + get<4>(t2)};
}

int res = INT32_MAX;
int min_visited[15];
void bt(tuple<int, int, int, int, int> t, int x) {
    if(get<0>(t) >= mp && get<1>(t) >= mf && get<2>(t) >= ms && get<3>(t) >= mv) {
        if(res > get<4>(t)) {
            res = get<4>(t);
            copy(visited, visited + n, min_visited);
        }
        return;
    }

    for(int d = x; d < n; d++) {
        if(visited[d]) continue;
        visited[d] = true;
        bt(t + v[d], d);
        visited[d] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mp >> mf >> ms >> mv;

    int tmp1, tmp2, tmp3, tmp4, tmp5;
    for(int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5;
        v.push_back({tmp1, tmp2, tmp3, tmp4, tmp5});
    }

    bt({0,0,0,0,0}, 0);

    if(res == INT32_MAX) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n';
        for(int i = 0; i < n; i++)
            if(min_visited[i]) cout << i+1 << " ";
        cout << '\n';
    }

    return 0;
}