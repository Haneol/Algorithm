#include <bits/stdc++.h>

using namespace std;

int a[2000001] = {1,}, b[2000001] = {1,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size, m, n, k, as, bs;
    cin >> size >> m >> n;
    
    vector<int> v;
    for(int i = 0; i < m; i++) cin >> k, v.push_back(k);

    int tmp;
    for(int i = 0; i < m; i++) {
        tmp = 0;
        for(int j = i; j < i+m-1; j++) {
            tmp += v[j%m];
            a[tmp]++;
        }
    }
    as = accumulate(v.begin(), v.end(), 0);
    if(as <= size) a[as]++;

    v.clear();
    for(int i = 0; i < n; i++) cin >> k, v.push_back(k);

    for(int i = 0; i < n; i++) {
        tmp = 0;
        for(int j = i; j < i+n-1; j++) {
            tmp += v[j%n];
            b[tmp]++;
        }
    }
    bs = accumulate(v.begin(), v.end(), 0);
    if(bs <= size) b[bs]++;


    int s = 0, e = size, cnt = 0;
    for(int i = 0; i <= size; i++) {
        cnt += a[s++] * b[e--];
    }

    cout << cnt << '\n';

    return 0;
}