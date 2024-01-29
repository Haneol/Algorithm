#include <bits/stdc++.h>

using namespace std;

int n, m, k;

void bt(vector<int>& vec, vector<int>& out, int x, int s) {
    if(m == x) {
        for(int i : out) cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = s; i < vec.size(); i++) {
        out.push_back(vec[i]);
        bt(vec, out, x+1, i);
        out.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    set<int> input;
    for(int i = 0; i < n; i++) {
        cin >> k;
        input.insert(k);
    }

    vector<int> v(input.begin(), input.end());
    sort(v.begin(), v.end());

    vector<int> o;

    bt(v, o, 0, 0);

    return 0;
}