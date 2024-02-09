#include <bits/stdc++.h>

using namespace std;

/*
    2263 트리의 순회
*/

int n, k;
vector<int> inorder, postorder;
bool visited[100001];

void preorder(int start_in, int end_in, int start_post, int end_post) {
    if(start_in > end_in || start_post > end_post) return;

    k = postorder[end_post];
    if(visited[k]) return;

    visited[k] = true;
    cout << k << ' ';

    int v;
    for(v = start_in; v <= end_in; v++) {
        if(inorder[v] == k) {
            break;
        }
    }

    int v2 = v - start_in + start_post;
    
    preorder(start_in, v-1, start_post, v2-1);
    preorder(v+1, end_in, v2, end_post-1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> k;
        inorder.push_back(k);
    }

    for(int i = 0; i < n; i++) {
        cin >> k;
        postorder.push_back(k);
    }

    preorder(0, n-1, 0, n-1);

    return 0;
}