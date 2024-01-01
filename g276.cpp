#include <bits/stdc++.h>
using namespace std;

struct P{
    int r;
    int c;
    int s;
    int t;
    int f;
};

int n, m, k, mp[105][105];
set<pair<int, int>> bombs;
P ps[505];

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            mp[i][j] = 0;
    }

    for (int i = 0; i < k; i++){
        ps[i].f = 1;
        cin >> ps[i].r >> ps[i].c >> ps[i].s >> ps[i].t; 
    }

    int t = k;
    while (t){
        bombs.clear();
        for (int i = 0; i < k; i++){
            if (!ps[i].f)
                continue;
            mp[ps[i].r][ps[i].c] = 2; //bomb;
        }
        for (int i = 0; i < k; i++){
            if (!ps[i].f)
                continue;
            ps[i].r += ps[i].s;
            ps[i].c += ps[i].t;
            if (mp[ps[i].r][ps[i].c] == 2 || !in(ps[i].r, ps[i].c)){
                t--;
                ps[i].f = 0;
                bombs.insert({ps[i].r, ps[i].c});
            }
        }

        for (auto b: bombs)
            mp[b.first][b.second] = 0;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 2)
                ans++;
        }
    }

    cout << ans;
}