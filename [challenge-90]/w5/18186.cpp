#include<bits/stdc++.h>
using namespace std;

long long arr[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long b, c;
    cin >> n >> b >> c;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    long long res = 0;
    int x, y, z;
    if(b>c){
        for(int i = 0; i < n-2; i++) {
            x = i;
            y = i+1;
            z = i+2;
            while(arr[x]) {
                if(arr[y]) {
                    if(arr[y] <= arr[z]) {
                        if(arr[y] > arr[x]) {
                            res += (b + c*2) * arr[x];
                            arr[y] -= arr[x];
                            arr[z] -= arr[x];
                            arr[x] = 0;
                        } else {
                            res += (b + c*2) * arr[y];
                            arr[x] -= arr[y];
                            arr[z] -= arr[y];
                            arr[y] = 0;
                        }
                    } else {
                        if(arr[y] > arr[x]) {
                            if(arr[y] - arr[z] > arr[x]) {
                                res += (b + c) * arr[x];
                                arr[y] -= arr[x];
                                arr[x] = 0;
                            } else {
                                res += (b + c) * (arr[y] - arr[z]);
                                arr[x] -= (arr[y] - arr[z]);
                                arr[y] -= (arr[y] - arr[z]);
                            }
                        } else {
                            if(arr[y] - arr[z] > arr[y]) {
                                res += (b + c) * arr[y];
                                arr[x] -= arr[y];
                                arr[y] = 0;
                            } else {
                                res += (b + c) * (arr[y] - arr[z]);
                                arr[x] -= (arr[y] - arr[z]);
                                arr[y] -= (arr[y] - arr[z]);
                            }
                        }
                    }
                } else {
                    res += b * arr[x];
                    arr[x] = 0;
                }
            }
        }

        x = n-2; y = n-1;
        while(arr[x]) {
            if(arr[y]) {
                if(arr[y] > arr[x]) {
                    res += (b + c) * arr[x];
                    arr[y] -= arr[x];
                    arr[x] = 0;
                } else {
                    res += (b + c) * arr[y];
                    arr[x] -= arr[y];
                    arr[y] = 0;
                }
            } else {
                res += b * arr[x];
                arr[x] = 0;
            }
        }

        x = n-1;
        while(arr[x]) {
            res += b * arr[x];
            arr[x] = 0;
        }
    } else {
        for(int i = 0; i < n; i++)
            res += b*arr[i];
    }

    cout << res << '\n';

    return 0;
}