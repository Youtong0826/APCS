#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, dn, t, s, w = 0, ht, m = INT_MIN;
    cin >> n;
    dn = n;
    while (n--){
        cin >> t >> s;
        if (s > m){
            m = s;
            ht = t;
        }

        if(s == -1)
            w++;
    }

    cout << max(0, m - dn - w*2) << ' ' << ht;
}