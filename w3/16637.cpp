#include<bits/stdc++.h>
using namespace std;

int n;
int num[19];
bool visited[19];
int n_num[19];

int calcul(int arr[], int x) {
    int output = arr[0] - '0';
    for(int i = 1; i < x - 1; i+=2) {
        switch(arr[i]) {
            case '+':
                output += arr[i+1] - '0';
                break;
            case '-':
                output -= arr[i+1] - '0';
                break;
            case '*':
                output *= arr[i+1] - '0';
                break;
        }
    }
    return output + '0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ch;
    for(int i = 0; i < n; i++) {
        ch = cin.get();
        while(ch == ' ' || ch == '\n' || ch == EOF) ch = cin.get();
        num[i] = ch;
    };

    if(n == 1) {
        cout << num[0] - '0' << '\n';
        return 0;
    }

    vector<int> v(n/2, 0);

    int output = calcul(num, n) - '0';
    int tmp[3];
    bool flag, flag2;
    for(int i = (n+1)/4; i >= 0; i--) {
        v[i] = 1;
        do {
            for(int z : v)
            flag = false; flag2 = false;
            for(int x : v) {
                if(flag) {
                    if(x == 1) {
                        flag2 = true;
                        break;
                    }
                    else flag = false;
                }
                else if(x == 1) flag = true;
            }
            if(flag2) continue;

            int j, k = 0;
            memset(visited, false, sizeof(visited));
            for(j = 0; j < n - 2; j++) {
                if(visited[j]) continue;

                if(v[(j+1)/2] && (num[j+1] == '+' || num[j+1] == '-' || num[j+1] == '*')) {
                    tmp[0] = num[j];
                    tmp[1] = num[j+1];
                    tmp[2] = num[j+2];

                    n_num[k] = calcul(tmp, 3);

                    visited[j] = true;
                    visited[j+1] = true;
                    visited[j+2] = true;
                } else n_num[k] = num[j];
                k++;
            }
            for(; j < n; j++) {
                if(!visited[j]){
                    n_num[k] = num[j];
                    k++;
                }
            }
            output = max(output, calcul(n_num, k) - '0');
        } while(next_permutation(v.begin(), v.end()));
    }

    cout << output << '\n';


    

    return 0;
}