#include<bits/stdc++.h>
using namespace std;

int arr[26] = {0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    cin >> str;

    sort(str.begin(), str.end());

    for(char c : str) arr[c - 'A']++;

    int tmp = -1;
    string output = "";
    for(int i = 0; i < 26; i++) {
        if(arr[i] % 2) {
            if(tmp == -1) {
                tmp = i;
                for(int k = 0; k < arr[i] / 2; k++) output = output + (char) (i + 'A');
            }
            else {
                cout << "I\'m Sorry Hansoo\n";
                return 0;
            }
        } else {
            for(int k = 0; k < arr[i] / 2; k++) output = output + (char) (i + 'A');
        }
    }
    
    cout << output;
    if (tmp != -1)cout << (char) (tmp + 'A');
    reverse(output.begin(), output.end());
    cout << output << '\n';


    return 0;
}