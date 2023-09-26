#include <bits/stdc++.h>
#define MAX 2000001

using namespace std;

int q[MAX];
int s, e;

void push(int x) {
    q[e++ % MAX] = x;
}

int size() {
    return e-s;
}

int empty() {
    if (size() == 0) return 1;
    else return 0;
}

int pop() {
    if (empty()) return -1;
    else return q[s++ % MAX];
}

int front() {
    if (empty()) return -1;
    else return q[s];
}

int back() {
    if(empty()) return -1;
    else return q[e-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string str;
    cin >> n;

    while(n--) {
        cin >> str;
        if(str == "push") {
            cin >> k;
            push(k);
        } else if(str == "pop") {
            cout << pop() << '\n';
        } else if(str == "size") {
            cout << size() << '\n';
        } else if(str == "empty") {
            cout << empty() << '\n';
        } else if(str == "front") {
            cout << front() << '\n';
        } else if(str == "back") {
            cout << back() << '\n';
        }
    }

    return 0;
}