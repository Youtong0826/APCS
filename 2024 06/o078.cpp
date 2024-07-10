#include <bits/stdc++.h>
#define sz(x) (int) x.size()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
using namespace std;

string k, s;
vector<string> v, v2;
vector<string> dp[11][11];
int l;

int main() {
    Youtong;
    cin >> k >> l >> s;

    for (int i = 0; i < sz(k); i++) {
        string s = "";
        s.push_back(k[i]);
        dp[i][1].push_back(s);
    }

    for (int i = 0; i < sz(s)-l+1; i++)
        v2.push_back(s.substr(i, l));

    for (int i = 0; i < sz(k); i++) {
        for (int j = 2; j <= l; j++) {
            for (auto cs: dp[i][j-1]) {
                cs.push_back(' ');
                for (int z = 0; z < sz(k); z++) {
                    cs[sz(cs)-1] = k[z];
                    if (sz(cs) == l)
                        v.push_back(cs);

                    else 
                        dp[i][j].push_back(cs);
                }
            }
        }
    }

    sort(all(v2));
    string ans = "";
    for (auto cs: v) {
        auto it = lower_bound(all(v2), cs);
        if (it == v2.end() || *it != cs) {
            if (ans == "")
                ans = cs;
            ans = min(ans, cs);
        }
    }

    cout << ans << '\n';
}