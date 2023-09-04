#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, team, g_time_i, tmp = -1, _times;
    int team1 = 0, team2 = 0, v_time1 = 0, v_time2 = 0;
    string g_time;

    cin >> n;
    for(int i = 0; i <= n; i++) {
        if(i != n) cin >> team >> g_time;
        else g_time = "48:00";

        g_time_i = ((g_time[0] - '0') * 10 + (g_time[1] - '0')) * 60 + (g_time[3] - '0') * 10 + (g_time[4] - '0');
        if(tmp != -1) _times = g_time_i - tmp;
        else _times = g_time_i;

        if(team1 > team2)
            v_time1 += _times;
        else if(team1 < team2)
            v_time2 += _times;

        if(team == 1)
            team1++;
        else if(team == 2)
            team2++;

        tmp = g_time_i;
    }

    cout << ((v_time1/60 <= 9) ? "0" + to_string(v_time1/60) : to_string(v_time1/60)) 
            << ":" << 
            ((v_time1%60 <= 9) ? "0" + to_string(v_time1%60) : to_string(v_time1%60)) << '\n';

    cout << ((v_time2/60 <= 9) ? "0" + to_string(v_time2/60) : to_string(v_time2/60)) 
            << ":" << 
            ((v_time2%60 <= 9) ? "0" + to_string(v_time2%60) : to_string(v_time2%60)) << '\n';

    return 0;
}