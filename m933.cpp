#include <bits/stdc++.h>
using namespace std;

int p, q, r, m;
vector<int> el;
vector<vector<int>> mp;

pair<int, int> dfs(int idx, int level){
    if (idx <= p)
        return {el[idx], level};

    if (idx > p+q && idx <= p+q+r)
        return dfs(mp[idx][0], level+1);

    
    if (el[idx] == 1){
        auto x = dfs(mp[idx][0], level+1);
        auto y = dfs(mp[idx][1], level+1);
        return {(x.first && y.first), max(x.second, y.second)};
    }

    if (el[idx] == 2){
        auto x = dfs(mp[idx][0], level+1);
        auto y = dfs(mp[idx][1], level+1);
        return {(x.first || y.first), max(x.second, y.second)};
    }

    if (el[idx] == 3){
        auto x = dfs(mp[idx][0], level+1);
        auto y = dfs(mp[idx][1], level+1);
        return {((!x.first && y.first) || (x.first && !y.first)), max(x.second, y.second)};
    }

    if (el[idx] == 4){
        auto x = dfs(mp[idx][0], level+1);
        return {!x.first, x.second};
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> p >> q >> r >> m;
    el.assign(p+q+1, 0);
    mp.assign(p+q+r+1, {});
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
        auto d = dfs(i, -1);
        logics.push_back(d.first);
        delay = max(delay, d.second);
    }
    cout << delay << '\n';
    for (auto i: logics)
        cout << i << ' ';
}