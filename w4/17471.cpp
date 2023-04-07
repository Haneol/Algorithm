// HINT : 조합 후 확인하기

#include<bits/stdc++.h>
using namespace std;

int n, popul[11];
vector<int> graph[11];
bool team[11];

bool check_valid() {
    bool visited[11] = {0,};

    queue<int> q;

    int x;

    q.push(1);
    while(!q.empty()) {
        x = q.front(); q.pop();

        if(visited[x]) continue;
        visited[x] = true;

        for(int k : graph[x]) {
            if(!visited[k] && team[x] == team[k]) q.push(k);
        }
    }

    int tmp = -1;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            tmp = i;
            break;
        }
    }

    if(tmp != -1) q.push(tmp);
    while(!q.empty()) {
        x = q.front(); q.pop();

        if(visited[x]) continue;
        visited[x] = true;

        for(int k : graph[x]) {
            if(!visited[k] && team[x] == team[k]) q.push(k);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp, tmp2;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> popul[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            cin >> tmp2;
            graph[i].push_back(tmp2);
        }
    }

    int res = INT32_MAX, sum_x, sum_y;
    for(int i = n; i >= 1; i--) {
        team[i] = 1;
        do {
            if(check_valid()) {
                sum_x = 0; sum_y = 0;
                for(int j = 1; j <= n; j++) {
                    if(team[j]) sum_x += popul[j];
                    else sum_y += popul[j];
                }
                if(sum_x != 0 || sum_y != 0) res = min(res, abs(sum_x - sum_y));
            }
        } while(next_permutation(team+1, team+n+1));
    }
    
    cout << (res == INT32_MAX ? -1 : res) << '\n';

    return 0;
}