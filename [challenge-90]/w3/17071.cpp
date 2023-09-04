#include<bits/stdc++.h>
using namespace std;

/* 
HINT : 
    t = t+2 = t+4 ... 이므로,
    짝수/홀수로 나누어 따로 계산한다.
    ->  동생이 이동했을 때 t 시간에 이미 t%2가 방문체크 되어있다면
        언제든 해당 위치를 재방문할 수 있다.
*/

bool visited[500001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;

    cin >> n >> k;
    
    queue<pair<int, int>> q;
    q.push({n,0});

    int x, t, dx[3], acc=1, size;
    bool flag = false;
    while(!q.empty()) {
        size = q.size();
        while(size--){
            tie(x, t) = q.front();
            q.pop();

            if(x == k || visited[k][t%2]) { flag = true; break; }

            dx[0] = x-1;
            dx[1] = x+1;
            dx[2] = x*2;
            
            for(int d = 0; d < 3; d++) {
                if(dx[d] < 0 || dx[d] > 500000) continue;

                if(!visited[dx[d]][(t+1)%2]) {
                    visited[dx[d]][(t+1)%2] = true;
                    q.push({dx[d], t+1});
                }
            }
        }
        if(flag) break;
        k += acc++;
        if(k > 500000) {
            cout << "-1\n";
            return 0;
        }  
    }

    cout << t << '\n';

    return 0;
}