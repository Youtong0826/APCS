#include <bits/stdc++.h>
using namespace std;

int m, n, h, mp[105][105];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool in(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}
int main(){
    cin >> m >> n >> h;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mp[i][j] = 0;
        

    int r, c, op, mx = INT_MIN, d;
    while (h--){
        cin >> r >> c >> op;
        
        if (op){
            mp[r][c] = 0;
            for (int i = 0; i < 4; i++)
                while(in(r+dx[i], c+dy[i]) && mp[r+dx[i]][c+dy[i]] != 2){
                    if (mp[r+dx[i]][c+dy[i]] == 1)
                        mp[r+dx[i]][c+dy[i]] = 0;
                    
                    r++; c++;
                }
        }

        else{
            mp[r][c] = 2;
            for (int i = 0; i < 4; i++){
                int tr = r, tc = c;
                while (in(tr+dx[i], tc+dy[i])){
                    tr += dx[i]; tc += dy[i];
                    if (mp[tr][tc] == 2){
                        while (1){
                            tr -= dx[i]; tc -= dy[i];
                            if(tr == r && tc == c)
                                break;

                            mp[tr][tc] = 1;
                            
                        }
                        break;
                    }
                    
                    cout << tr << ' ' << tc << '\n';
                }
                cout << '\n';
                
            }
                
        }

        d = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] == 1 || mp[i][j] == 2)
                    d++;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                cout << mp[i][j] << ' ';
            cout << '\n';
        }

        mx = max(mx, d);
    }
    
    cout << mx << '\n' << d;
}