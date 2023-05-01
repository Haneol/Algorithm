#include<bits/stdc++.h>
using namespace std;

int n, k, x;
int arr[101];

bool cmp(int a, int b) {
    int tmp = x + 1;
    while(tmp < k) {
        if(arr[tmp] == a) return false;
        else if(arr[tmp] == b) return true;
        tmp++;
    }
    return true;
}

bool find_v(vector<int> v, int k) {
    sort(v.begin(), v.end());
    
    int start = 0, end = v.size() - 1, mid;
    
    while(start <= end) {
        mid = (start + end) / 2;
        if(v[mid] == k) {
            return true;
        } else if(v[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++) cin >> arr[i];

    int res = 0;
    vector<int> v;
    for(x = 0; x < k; x++) {
        int i = x;
        if(v.empty()) {
            v.emplace_back(arr[x]);
        } else if(!find_v(v, arr[x])) {
            if(v.size() < n) v.emplace_back(arr[x]);
            else {
                v[0] = arr[x];
                res++;
            }
        }
        sort(v.begin(), v.end(), cmp);
    }

    cout << res << '\n';

    return 0;
}