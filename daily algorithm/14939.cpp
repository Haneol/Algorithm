#include <bits/stdc++.h>

using namespace std;

/*
    14939 불 끄기
*/

char ch;
int board[10];
int new_board[10];

int light() {
    int res = -1;
    int cnt;
    for(int i = 0; i < 1024; i++) {
        copy(&board[0], &board[10], new_board);
        cnt = 0;

        for(int j = 0; j < 10; j++) {
            if(i & (1 << j)) {
                new_board[0] = new_board[0] ^ (1 << j);
                if(j > 0) new_board[0] = new_board[0] ^ (1 << j-1);
                if(j < 9) new_board[0] = new_board[0] ^ (1 << j+1);
                new_board[1] = new_board[1] ^ (1 << j);
                cnt++;
            }
        }

        for(int j = 1; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(new_board[j-1] & (1 << k)) {
                    new_board[j-1] = new_board[j-1] ^ (1 << k);
                    new_board[j] = new_board[j] ^ (1 << k);
                    if(k > 0) new_board[j] = new_board[j] ^ (1 << k-1);
                    if(k < 9) new_board[j] = new_board[j] ^ (1 << k+1);
                    if(j < 9) new_board[j+1] = new_board[j+1] ^ (1 << k);
                    cnt++;
                }
            }
        }

        if(!new_board[9]) {
            if(res == -1) {
                res = cnt;
            } else {
                res = min(res, cnt);
            }
        }
    }

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> ch;
            if(ch == 'O') {
                board[i] = board[i] | (1 << j);
            }
        }
    }

    cout << light();

    return 0;
}