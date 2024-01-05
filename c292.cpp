#include <bits/stdc++.h>
using namespace std;

bool vis[50][50], fi = 1;
int n, d, mp[50][50];

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

// dir: 0 西 1 北 2 東 3 南
void f(int x, int y, int dir){
    if (!in(x, y))
        return;

    cout << mp[x][y];
    vis[x][y] = 1;

    switch (dir){
    case 0:
        if (vis[x-1][y] || fi){
            fi = 0;
            f(x, y-1, dir);
        }

        else
            f(x-1, y, (dir+1)%4);

        break;

    case 1:
        if (vis[x][y+1] || fi){
            fi = 0;
            f(x-1, y, dir);
        }

        else
            f(x, y+1, (dir+1)%4);

        break;
    
    case 2:
        if (vis[x+1][y] || fi){
            fi = 0;
            f(x, y+1, dir);
        }

        else
            f(x+1, y, (dir+1)%4);

        break;
    
    case 3:
        if (vis[x][y-1] || fi){
            fi = 0;
            f(x+1, y, dir);
        }

        else
            f(x, y-1, (dir+1)%4);

        break;

    default:
        break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mp[i][j];
        }
    }

    f(n/2, n/2, d);
}