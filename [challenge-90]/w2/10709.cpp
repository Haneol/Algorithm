#include<bits/stdc++.h>
using namespace std;

int arr[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    char tmp;
    cin >> x >> y;

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            tmp = cin.get();
            if(tmp == '\n') tmp = cin.get();

            if(j == 0) {
                if(tmp == 'c') {
                    arr[i][j] = 0;
                } else if(tmp == '.') {
                    arr[i][j] = -1;
                }
            } else {
                if(tmp == 'c') arr[i][j] = 0;
                else if(arr[i][j-1] == -1) arr[i][j] = -1;
                else arr[i][j] = arr[i][j-1] + 1;
            }
        }
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}