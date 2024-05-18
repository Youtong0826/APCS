#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> g;
int md = -1, mi = -1;

void dfs(int idx, int father, int depth){
    //cout << idx << ' ' << depth << '\n';
    //chk[idx] = 1;
    for (auto i: g[idx]){
        if (i != father){
           dfs(i, idx, depth+1);
        }
    }

    if (depth > md){
        md = depth;
        mi = idx;
    }
}

signed main(){
    Youtong;
    int n, a, b;
    cin >> n;

    g.assign(n, {});
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    // for (auto i: g[0])
    //     cout << i << ' ';
    // cout << '\n';

    dfs(0, -1, 0);
    //cout << md << ' ' << mi << '\n';
    dfs(mi, -1, 0);
    cout << md << '\n';
}