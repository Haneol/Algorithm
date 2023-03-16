#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > house, chicken;
int dist[100];

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

    int sum = INT32_MAX;
    do {
        fill(&dist[0], &dist[100], INT32_MAX);
        for(int i = 0; i < select.size(); i++) {
            if(select[i] == 1) {
                for(int j = 0; j < house.size(); j++) {
                    dist[j] = min(dist[j], abs(house[j].first - chicken[i].first) + abs(house[j].second - chicken[i].second));
                }
            }
        }
        sum = min(sum, accumulate(dist, dist + house.size(), 0));
    } while(next_permutation(select.begin(), select.end()));

    cout << sum << '\n';

    return 0;
}