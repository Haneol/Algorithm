#include<bits/stdc++.h>
using namespace std;

vector<int> tree[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, root, removed, tmp, count = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp == -1) root = i;
        else tree[tmp].push_back(i);
    }
    
    cin >> removed;
    queue<int> q;
    bool flag;
    if(removed != root) {
        q.push(root);
        while(!q.empty()) {
            tmp = q.front(); q.pop();

            flag = false;
            for(int i : tree[tmp]) {
                if(i != removed) {
                    q.push(i);
                    flag = true;
                }
            }

            if(!flag) count++;
        }
    }

    cout << count << '\n';
    

    return 0;
}