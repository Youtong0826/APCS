#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k] 第 i 個病毒的第 j 個字元是 k 時的最小來源
const int maxn = 1e3+3;
int dp[maxn][100][5]; // 0 1 2 3 A U C G

struct pt {
    int id;
    string rna;
};

vector<vector<pt>> g;

void dfs(pt idx){
    if (g[idx.id].empty()) {

    }
    for (auto i: g[idx.id]){
        if (i.rna == idx.rna)
            dp[i.id];
    }
}

int main(){
    int n, m, a, b;
    pt root;
    string s;
    cin >> n >> m;
    g.assign(n+1, {});
    for (int i = 1; i < n; i++){
        cin >> a >> b >> s;
        if (a == b){
            root = {a, s};
            continue;
        }
        g[b].push_back({a, s});
    }
}