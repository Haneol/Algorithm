#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char str[n];
    cin >> str;

    if(n == 1) {
        cout << str[0] << '\n';
        return 0;
    }

    int v[n/2];
    stack<long long> s, s2;
    vector<long long> res;
    long long x, k, size, value;
    long long output = LLONG_MIN;
    bool flag, flag2;
    for(int i = n/2-1; i >= 0; i--) {
        v[i] = 1;
        do{
            flag = false; flag2 = false;
            for(int y : v) {
                if(y == 1) {
                    if(flag) {
                        flag2 = true;
                        break;
                    }
                    flag = true;
                } else flag = false;
            }
            if(flag2) continue;

            for(int c = n - 1; c >= 0; c--) s.push(str[c]);

            k = 0;
            while(!s.empty()) {
                x = s.top(); s.pop();
                if(x == '*' || x == '+' || x == '-') {
                    if(v[k] == 1) {
                        switch(x) {
                            case '*':
                                x = ((s2.top() - '0') * (s.top() - '0')) + '0';
                                s2.pop();
                                break;
                            case '+':
                                x = ((s2.top() - '0') + (s.top() - '0')) + '0';
                                s2.pop();
                                break;
                            case '-':
                                x = ((s2.top() - '0') - (s.top() - '0')) + '0';
                                s2.pop();
                                break;
                        }
                        s.pop();
                    }
                    k++;
                }
                s2.push(x);
            }

            size = s2.size();
            res.clear();
            while(!s2.empty()) {
                s.push(s2.top()); s2.pop();
            }

            while(!s.empty()) {
                res.push_back(s.top()); s.pop();
            }

            value = res[0] - '0';
            for(int j = 1; j < size; j++) {
                if(res[j] == '+')
                    value += res[j+1] - '0';
                else if(res[j] == '-')
                    value -= res[j+1] - '0';
                else if(res[j] == '*')
                    value *= res[j+1] - '0';
            }

            output = max(output, value);
        } while(next_permutation(v, v + n/2));
    }

    cout << output << '\n';

    return 0;
}