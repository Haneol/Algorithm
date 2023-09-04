#include<bits/stdc++.h>
using namespace std;

int arr[64][64];

string dnq(pair<int, int> s, pair<int, int> e) {
    int tmp = -1;
    bool flag = false;
    for(int i = s.first; i <= e.first; i++) {
        for(int j = s.second; j <= e.second; j++) {
            if(tmp == -1) tmp = arr[i][j];
            else if(tmp != arr[i][j]) {
                flag = true; break;
            }
        }
        if(flag) break;
    }

    if(flag) {
        return "("  + dnq(s, {(s.first + e.first)/2, (s.second + e.second)/2}) 
                    + dnq({s.first, (s.second + e.second)/2 + 1}, {(s.first + e.first)/2, e.second}) 
                    + dnq({(s.first + e.first)/2 + 1, s.second}, {e.first, (s.second + e.second)/2})
                    + dnq({(s.first + e.first)/2 + 1, (s.second + e.second)/2 + 1}, e) + ")";
    }
    else {
        return to_string(tmp);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            tmp = cin.get();
            if(tmp == '\n') tmp = cin.get();
            arr[i][j] = tmp - '0';
        }
    
    cout << dnq({0,0}, {n-1,n-1}) << '\n';

    return 0;
}