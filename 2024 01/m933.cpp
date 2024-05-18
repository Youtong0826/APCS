#include <bits/stdc++.h>
using namespace std;

int p, q, r, m;
vector<int> el;
vector<bool> vis;
vector<vector<int>> mp;
vector<pair<int, int>> dp;

pair<int, int> dfs(int idx){
    if (idx <= p){
        vis[idx] = 1;
        return dp[idx] = {el[idx], 0};
    }
        
    if (idx > p+q && idx <= p+q+r)
        return dfs(mp[idx][0]);
    
    if (vis[idx])
        return dp[idx];

    vis[idx] = 1;
    auto x = dfs(mp[idx][0]);

    if (el[idx] == 4)
        return dp[idx] = {!x.first, x.second+1};

    auto y = dfs(mp[idx][1]);

    if (el[idx] == 1)
        return dp[idx] = {(x.first && y.first), max(x.second, y.second)+1};

    if (el[idx] == 2)
        return dp[idx] = {(x.first || y.first), max(x.second, y.second)+1};

    if (el[idx] == 3)
        return dp[idx] = {(x.first ^ y.first), max(x.second, y.second)+1};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> p >> q >> r >> m;

    el.assign(p+q+1, 0);
    mp.assign(p+q+r+1, {});
    vis.assign(p+q+r+1, 0);
    dp.resize(p+q+r+1);

    for (int i = 1; i <= p+q; i++)
        cin >> el[i];

    int a, b;
    while (m--){
        cin >> a >> b;
        mp[b].push_back(a);
    }

    int delay = INT_MIN;
    vector<int> logics;
    for (int i = p+q+1; i <= p+q+r; i++){
        auto d = dfs(i);
        logics.push_back(d.first);
        delay = max(delay, d.second);
    }

    cout << delay << '\n';
    for (auto i: logics)
        cout << i << ' ';
}