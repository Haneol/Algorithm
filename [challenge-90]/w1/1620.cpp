#include<bits/stdc++.h>
using namespace std;

map<string, int> _map;
map<int, string> _map2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        _map.insert({tmp, i});
        _map2.insert({i, tmp});
    }

    for(int i = 0; i < m; i++) {
        cin >> tmp;
        
        if(atoi(tmp.c_str())) {
            cout << _map2[atoi(tmp.c_str())] << '\n';
        }
        else {
            cout << _map[tmp] << '\n';
        }
    }

    return 0;
}