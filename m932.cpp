#include <bits/stdc++.h>
using namespace std;

int m, n, k;
char mp[25][25];
bool vis[60];

int cvt(char c){
    return (c >= 'A' && c <= 'Z')? c-'A':c-'a'+26;
}

bool in(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0 ; j < n; j++)
            cin >> mp[i][j];

    int c, x = m-1, y = 0, t = 0;
    while (k--){
        cin >> c;

        switch (c){
        case 0:
            if (in(x-1, y)) x--;
            break;

        case 1:
            if (in(x, y+1)) y++;
            break;

        case 2:
            if (in(x+1, y+1)) x++, y++;
            break;

        case 3:
            if (in(x+1, y)) x++;
            break;

        case 4:
            if (in(x, y-1)) y--;
            break;

        case 5:
            if (in(x-1, y-1)) x--, y--;
            break;
        }

        if (!vis[cvt(mp[x][y])])
            t++;
        
        vis[cvt(mp[x][y])] = 1;
        cout << mp[x][y];
    }

    cout << '\n' << t;
}