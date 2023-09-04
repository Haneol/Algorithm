#include<bits/stdc++.h>
using namespace std;

int main(){int n;std::cin>>n;

    int res = 0;
    for(int i = 0; i < 7; i++)
        if(bitset<7>(n).test(i)) res++;

    cout << res << '\n';

    return 0;
}