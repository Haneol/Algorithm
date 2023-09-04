#include<bits/stdc++.h>
using namespace std;

int T;
int arr[1001][8];
int k[1001];

void rotate(int n, int d) {
    bool mask[1001] = {false,};

    for(int i = 0; i < T-1; i++) {
        if(arr[i][(k[i]+2)%8 < 0 ? (k[i]+2)%8+8 : (k[i]+2)%8] != arr[i+1][(k[i+1]+6)%8 < 0 ? (k[i+1]+6)%8+8 : (k[i+1]+6)%8]) {
            mask[i] = true;
        }
    }

    if(d == 1) k[n]--;
    else k[n]++;
    
    int dir = d * -1;
    for(int i = n+1; i < T; i++) {
        if(!mask[i-1]) break;

        if(dir == 1) k[i]--;
        else k[i]++;
        
        dir *= -1;
    }

    dir = d * -1;
    for(int i = n; i > 0; i--) {
        if(!mask[i-1]) break;

        if(dir == 1) k[i-1]--;
        else k[i-1]++;
        
        dir *= -1;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    string tmp;
    for(int i = 0; i < T; i++) {
        cin >> tmp;
        for(int j = 0; j < 8; j++)
            arr[i][j] = tmp[j] - '0';
    }

    int K;
    cin >> K;

    int n, d;
    for(int i = 0; i < K; i++) {
        cin >> n >> d;
        rotate(n-1, d);
    }

    int res = 0;
    for(int i = 0; i < T; i++)
        if(arr[i][k[i]%8 < 0 ? k[i]%8+8 : k[i]%8]) res++;

    cout << res << '\n';

    return 0;
}