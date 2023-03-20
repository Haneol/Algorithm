#include<bits/stdc++.h>
using namespace std;

tuple<int, int, int> dir[6] = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9}};

bool visited[61][61][61];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, initial_health[3] = {0,};
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> initial_health[i];

    queue<tuple<int, int, int> > scv;
    scv.push({initial_health[0], initial_health[1], initial_health[2]});

    int h1, h2, h3, next_h1, next_h2, next_h3, size, times = 0;
    bool flag = false;
    while(!scv.empty()) {
        size = scv.size();
        while(size--){
            h1 = get<0>(scv.front());
            h2 = get<1>(scv.front());
            h3 = get<2>(scv.front());
            scv.pop();

            if(h1 <= 0 && h2 <= 0 && h3 <= 0) { flag = true; break; }
            if(visited[h1][h2][h3]) continue;
            visited[h1][h2][h3] = true;

            for(int d = 0; d < 6; d++) {
                next_h1 = h1 - get<0>(dir[d]) < 0 ? 0 : h1 - get<0>(dir[d]);
                next_h2 = h2 - get<1>(dir[d]) < 0 ? 0 : h2 - get<1>(dir[d]);
                next_h3 = h3 - get<2>(dir[d]) < 0 ? 0 : h3 - get<2>(dir[d]);

                if(!visited[next_h1][next_h2][next_h3]) scv.push({next_h1, next_h2, next_h3});
            }
        }
        times++;
        if(flag) break;
    }

    cout << times - 1 << '\n';

    return 0;
}