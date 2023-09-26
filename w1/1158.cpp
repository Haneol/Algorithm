#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    list<int> li;
    list<int>::iterator it;

    cin >> n >> k;

    for(int i = 0; i < n; i++) li.push_back(i+1);

    cout << '<';

    it = li.begin();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k-1; j++) {
            it++;
            if(it == li.end()) it = li.begin();
        }
        cout << *it;
        it = li.erase(it);
        if(it == li.end()) it = li.begin();
        if(i < n - 1) cout << ", ";
    }
    cout << ">\n";
}