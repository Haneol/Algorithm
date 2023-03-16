#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > house, chicken;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 1) house.push_back({i, j});
            else if(tmp == 2) chicken.push_back({i, j});
        }
    }

    vector<int> select;
    for(int i = 0; i < chicken.size() - m; i++) select.emplace_back(0);
    for(int i = 0; i < m; i++) select.emplace_back(1);

    do {
        
    } while(next_permutation(select.begin(), select.end()));

    cout << '\n';

    return 0;
}