#include <bits/stdc++.h>
#define pii pair<int,int>
#define l first
#define r second
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int maxn = 2e6+5;

// 同 h029

int n, m, a, b, c;
int w[maxn];
vector<pii> g;
vector<int> box;

void join(int val, int idx){
    w[idx] += val;
    if (idx >= n){
        cout << idx << ' ';
        return;
    }
    // cout << idx << ' ' << w[g[idx][0]] << ' ' << w[g[idx][1]] << '\n';
    if (w[g[idx].r] >= w[g[idx].l]) 
        join(val, g[idx].l);
    
    else 
        join(val, g[idx].r);
    
}

int dfs(int idx){
    if (idx >= n)
        return w[idx];

    return w[idx] = dfs(g[idx].l) + dfs(g[idx].r);
}

signed main(){
    Youtong;
    cin >> n >> m;
    g.resize(n+1);
    box.resize(m);
    for (int i = n; i < 2*n; i++)
        cin >> w[i];
    
    for (auto &i: box)
        cin >> i;

    for (int i = 1; i < n; i++){
        cin >> a >> b >> c;
        g[a] = {b, c};
    }

    w[1] = dfs(1);

    for (auto i: box){
        // cout << i << '\n';
        join(i, 1);
    }
}