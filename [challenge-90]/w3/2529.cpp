#include<bits/stdc++.h>
using namespace std;

char arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];

    stack<int> s;
    int num = 9;
    for(int i = 0; i < n; i++) {
        if(arr[i] == '<') {
            s.push(num--);
        } else {
            cout << num--;
            while(!s.empty()) {cout << s.top(); s.pop();}
        }
    }
    cout << num;
    while(!s.empty()) {cout << s.top(); s.pop();}
    cout << '\n';

    num = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == '>') {
            s.push(num++);
        } else {
            cout << num++;
            while(!s.empty()) {cout << s.top(); s.pop();}
        }
    }
    cout << num;
    while(!s.empty()) {cout << s.top(); s.pop();}
    cout << '\n';

    return 0;
}