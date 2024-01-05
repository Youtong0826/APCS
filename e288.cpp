#include <bits/stdc++.h>
using namespace std;

int m, n;
string cp[500010];
string rcp[500010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        cp[i].assign(m, '0');
        rcp[i].assign(m, '1');
        // cout << cp[i] << ' ' << rcp[i] << '\n'
    }
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < s.size(); j++){
            if (isupper(s[j]))
                cp[i][s[j]-'A'] = '1';
            else
                cp[i][s[j]-'a'+26] = '1';
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (cp[i][j] == '1')
                rcp[i][j] = '0';
            // cout << rcp[i][j];
        }
        // cout << '\n';
    }

    sort(cp, cp+n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        // cout << cp[i] << ' ' << rcp[i] << '\n'
        //      << binary_search(cp, cp+n, rcp[i]) << '\n';
        if (binary_search(cp, cp+n, rcp[i])){
            ans++;
        }
    }

    cout << ans/2 << '\n';
}