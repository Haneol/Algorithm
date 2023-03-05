#include<bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
    return s1.length() == s2.length() ? s1 < s2 : s1.length() < s2.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> v;
    string str, tmp;
    bool flag;
    for(int i = 0; i < n; i++) {
        cin >> str;

        tmp = "";
        flag = false;
        for(char c : str) {
            if(c >= '0' && c <= '9') {
                
                if(tmp[0] == '0') tmp = c;
                else tmp = tmp + c;

                flag = true;
            } else if(flag) {
                v.emplace_back(tmp);
                flag = false;
                tmp = "";
            }
        }
        if(flag) {
            v.emplace_back(tmp);
            flag = false;
            tmp = "";
        }
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) cout << v[i] << '\n';
        else cout << v[i];
    }

    return 0;
}