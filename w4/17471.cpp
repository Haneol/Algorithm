#include<bits/stdc++.h>
using namespace std;

int n;
int popul[11];
bool visited[11];
vector<int> graph[11];

bool check_valid(int x) {
    int bit_mask = 0;
    bool flag = false;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(!flag) {
                for(int k : graph[i]) {
                    bit_mask = bit_mask | (1 << (k-1));
                }
                flag = true;
            } else if(bit_mask & (1 << (i-1))) {
                bit_mask = bit_mask & ~(1 << (i-1));
            }
        }
    }
    if(flag) {
        if(bit_mask != 0) return false;
        else return true;
    } else return false;
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

    queue<int> q;

    int x, sum;
    int acc = accumulate(popul, popul + n + 1, 0);
    int res = acc;
    for(int i = 1; i <= n; i++) {
        q.push(i);
        sum = popul[i];
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        while(!q.empty()) {
            x = q.front(); q.pop();

            for(int k : graph[x]) {
                if(!visited[k]) {
                    visited[k] = true;
                    sum += popul[k];
                    if(check_valid(k)) {
                        res = min(res, abs(acc-sum*2));
                        cout << "<" << res << ">\n";
                    }
                    q.push(k);
                }
            }
        }
        cout << "--\n";
    }

    cout << (res == acc ? -1 : res)<< '\n';


    return 0;
}