#include <bits/stdc++.h>
using namespace std;

const int mx[4] = {1, 0, -1, 0};
const int my[4] = {0, 1, 0, -1};
bool vis[105][105];
int n, m, sum = 0, mp[100][100];

bool in(int x, int y){
    return 0<=x && x<n && 0<=y && y<m;
}

void dfs(int x, int y){
    int mi = INT_MAX, mix, miy;

    for (int i=0 ; i<4 ; i++){
        int a = x+mx[i], b = y+my[i];
        if (in(a, b) && !vis[a][b]){
            if (mp[a][b] < mi){
                mi = mp[a][b];
                mix = a;
                miy = b;
            }
        }
    }

    if (mi == INT_MAX)
        return;
    
    sum += mi;
    vis[mix][miy] = 1;
    dfs(mix, miy);
}
int main(){
    int minS = INT_MAX, x, y;
    cin >> n >> m;
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
            if (mp[i][j] < minS){
                minS = mp[i][j];
                x = i;
                y = j;
            }
        }
    }
    vis[x][y] = 1;
    dfs(x, y);
    cout << sum+mp[x][y];
}