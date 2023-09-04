// C++의 MOD 연산은 음수 값이 나올 수 있다

#include<bits/stdc++.h>
using namespace std;

#define APPLE 2
#define SNAKE 1

int board[101][101];
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,l;
    cin >> n >> k;

    int tmp,tmp2;
    for(int i = 0; i < k; i++) {
        cin >> tmp >> tmp2;
        board[tmp-1][tmp2-1] = APPLE;
    }

    cin >> l;

    vector<pair<int,char>> snake_state;
    char tmp3;
    for(int i = 0; i < l; i++) {
        cin >> tmp2 >> tmp3;
        snake_state.push_back({tmp2, tmp3});
    }

    int t = 0, d = 0, inx = 0, x, y;
    board[0][0] = SNAKE;
    deque<pair<int,int>> snake;
    snake.push_front({0,0});
    while(true) {
        if(inx < l && snake_state[inx].first == t) {
            if(snake_state[inx].second == 'D') d++;
            else d--;
            inx++;
        }

        x = snake.front().first + dir[d%4 < 0 ? 4+d%4 : d%4].first;
        y = snake.front().second + dir[d%4 < 0 ? 4+d%4 : d%4].second;
        
        t++;

        if(x < 0 || y < 0 || x >= n || y >= n) break;
        if(board[x][y] == SNAKE) break;

        if(board[x][y] == APPLE) {
            board[x][y] = SNAKE;
            snake.push_front({x,y});
        } else {
            board[x][y] = SNAKE;
            snake.push_front({x,y});
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
    }

    cout << t << '\n';

    return 0;
}