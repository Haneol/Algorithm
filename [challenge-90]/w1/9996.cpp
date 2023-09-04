#include<bits/stdc++.h>
using namespace std;

bool isCorrect(string pattern, string str) {

    vector<string> patterns;
    stringstream ss(pattern);
    string tmp;

    while(getline(ss, tmp, '*')) {
        patterns.push_back(tmp);
    }

    int k = 0;
    bool flag = false;
    for(int i = 0 ; i < patterns.size(); i++) {
        if (i == patterns.size() - 1) {
            int last = str.length() - patterns[i].length();
            if(last <= 0) return false;
            if(patterns[i].compare(str.substr(last, patterns[i].length())) == 0 
                && last >= k) return true;
            else return false;
        } else if(i == 0) {
            int j = 0;
            flag = false;
            while(str[k] == patterns[i][j]) { 
                k++; j++;
                if(k >= str.size()) return false;
                if(j >= patterns[i].length()) { flag = true; break; }
            }
            if(!flag) return false;
        } else {
            while(true)
            {
                while(str[k] != patterns[i][0]) k++;
                int j = 0;
                flag = false;
                while(str[k] == patterns[i][j]) { 
                    k++; j++;
                    if(k >= str.size()) return false;
                    if(j >= patterns[i].length()) { flag = true; break; }
                }
                if(flag) break;
                else return false;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;
    string str;
    cin >> n >> pattern;

    for(int i = 0; i < n; i++) {
        cin >> str;
        cout << (isCorrect(pattern, str) ? "DA\n" : "NE\n");
    }

    return 0;
}