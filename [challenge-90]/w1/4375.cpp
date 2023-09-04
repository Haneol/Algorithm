#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long tmp;
    int output;

    int n;
    string line;
    vector<int> v;
    while(getline(cin, line)) {
        n = atoi(line.c_str());

        tmp = 0;
        output = 0;
        
        while(true) {
            tmp = tmp * 10 + 1;
            output++;
            if (!(tmp %= n)) {
                v.push_back(output);
                break;
            }
        }
    }

    for(int i : v) cout << i << '\n';

    return 0;
}