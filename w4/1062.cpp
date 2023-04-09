#include<bits/stdc++.h>
using namespace std;

int n, k;
int res = 0;
vector<int> words;

bool comp(pair<int,int> x, pair<int,int> y) {
    return x.second > y.second;
}

int charToNum(char c) {
    if(c < 'c') return c - 'a' - 1;
    else if(c < 'i') return c - 'a' - 2;
    else if(c < 'n') return c - 'a' - 3;
    else if(c < 't') return c - 'a' - 4;
    else return c - 'a' - 5;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    k -= 5;

    string str;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> str;
        tmp = 0;
        for(char c : str) {
            if(c == '\n' || c == ' ' || c == EOF || c == '\0'
                || c == 'a' || c == 'c' || c == 'i' || c == 'n' || c == 't') continue;

            tmp = tmp | (1 << charToNum(c));
        }
        words.emplace_back(tmp);
    }

    if(k == 0) {
        for(int i : words) {
            if(i == 0) res++;
        }
        cout << res << '\n';
        return 0;
    } else if(k < 0) {
        cout << 0 << '\n';
        return 0;
    }

    bool flag;
    int cnt;
    int next[21] = {0,};
    for(int i = 20; i >= 21-k; i--) next[i] = 1;
    
    do {
        cnt = 0;
        for(int i : words) {
            flag = true;

            for(int j = 0; j < 21; j++) {
                if((i & (1 << j)) && !next[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        res = max(res, cnt);
    }while(next_permutation(next, next + 21));

    cout << res << '\n';

    return 0;
}