#include <bits/stdc++.h>
using namespace std;

const int mx[4] = {1, 0, -1, 0}, my[4] = {0, 1, 0, -1};
bool vis[105][105];
int n, m, mp[105][105];

bool in(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main(){
    int mn = INT_MAX, x, y;
    cin >> n >> m;
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
            if (mp[i][j] < mn){
                mn = mp[i][j];
                x = i;
                y = j;
            }
        }
    }

    vis[x][y] = 1;
    int sum = mp[x][y];
    while (1){
        int mi = INT_MAX, mix, miy;
        for (int i = 0 ; i < 4 ; i++){
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
            break;

        sum += mi;
        vis[mix][miy] = 1;
        x = mix, y = miy;
    }
    
    cout << sum;
}