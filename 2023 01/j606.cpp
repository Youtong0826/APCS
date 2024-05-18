// 5 4 1
// abcde
// 2 1 3 5 4 # baced
// 5 1 2 4 3 # acdeb
// 4 1 2 3 5 # cdeab
// 3 1 4 5 2 # dbcea

#include <bits/stdc++.h>
using namespace std;

vector<string> p;
int main(){
    string s, t(' ', 25);
    int k, q, r, c;
    cin >> k >> q >> r >> s;
    while (q--){
        for (int i = 0; i < k; i++){
            cin >> c;
            t[c-1] = s[i];
        }
        p.push_back(t);
        s = t;
    }
    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < p.size(); j++){
            cout << p[j][i];
        }
        cout << '\n';
    }
}