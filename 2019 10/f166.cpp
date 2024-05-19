#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int n, p, L, R;
int s[maxn];
bool vis[maxn];
queue<pair<int, int>> q;

void bfs(){
    while (q.size()){
        auto [t, idx] = q.front();
        q.pop();
        if (idx < n && idx >= 0 && s[idx] < n && s[idx] >= 0 && !vis[idx] ){
            vis[idx] = 1;
            // cout << idx << ' ' << s[idx] << '\n';
            if (s[idx] == p){
                cout << t << '\n';
                return;
            }

            q.push({t+1, s[idx]-L});
            q.push({t+1, s[idx]+R});
        }
    }

    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> L >> R;
    
    for (int i = 0; i < n; i++)
        cin >> s[i];

    if (p == 0){
        cout << 0 << '\n';
        return 0;
    }
    q.push({0, 0});
    bfs();
}