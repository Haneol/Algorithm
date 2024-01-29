#include <bits/stdc++.h>

using namespace std;

string str;
int k, n, d, prev_n;
bool dir;
deque<int> dq[4];

void next_state(int x) {
    if(dir) {
        dq[x].push_front(dq[x].back());
        dq[x].pop_back();
    } else {
        dq[x].push_back(dq[x].front());
        dq[x].pop_front();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i++) {
        cin >> str;
        for(char c : str) {
            dq[i].push_back(c - '0');
        }
    }

    cin >> k;
    while(k--) {
        cin >> n >> d;
        n--;
        dir = (d == 1 ? true : false);
        next_state(n);

        prev_n = n;
        for(int i = n + 1; i < 4; i++) {
            if(dir) {
                if(dq[prev_n][3] == dq[i][6]) break;
            }
            else {
                if(dq[prev_n][1] == dq[i][6]) break;
            }
            
            dir = !dir;
            next_state(i);
            prev_n = i;
        }

        prev_n = n;
        dir = (d == 1 ? true : false);
        for(int i = n - 1; i >= 0; i--) {
            if(dir) {
                if(dq[prev_n][7] == dq[i][2]) break;
            }
            else {
                if(dq[prev_n][5] == dq[i][2]) break;
            }
            
            dir = !dir;
            next_state(i);
            prev_n = i;
        }
    }

    int res = 0;
    if (dq[0][0] == 1) res += 1;
    if (dq[1][0] == 1) res += 2;
    if (dq[2][0] == 1) res += 4;
    if (dq[3][0] == 1) res += 8;

    cout << res << '\n';

    return 0;
}