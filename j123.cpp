#include <bits/stdc++.h>
using namespace std;

bool mp[35][55];
int rd[35];

int main(){
    int r, c, n, y, p = 0;

    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mp[r][c] = 0;

    for (int i = 0; i < r; i++)
        rd[i] = c;

    char a;
    int s = r*c;
    while (n--){
        cin >> a >> y;
        bool f = 0;
        int mr;

        switch (a){
        case 'A':

            for (int i = y; i < y+4; i++){
                if (rd[i] < 1){
                    f = 1;
                    break;
                }
                mr = max(mr, c-rd[i]);
            }

            if (f){
                p++;
                break;
            }

            s -= 4;
            for (int i = y; i < y+4; i++){
                for (int j = mr; j < mr+1; j++)
                    mp[i][j] = 1;

                rd[i] = c - mr - 1;
            }
            break;
        
        case 'B':
            if (rd[y] >= 3){
                s -= 3;
                for (int i = c-rd[y]; i < c-rd[y]+3; i++)
                    mp[y][i] = 1;
                
                rd[y] -= 3;
            }
            else
                p++;

            break;

        case 'C':
            for (int i = y; i < y+2; i++){
                if (rd[i] < 2){
                    f = 1;
                    break;
                }
            
                mr = max(mr, c-rd[i]);
            }

            if (f){
                p++;
                break;
            }

            s -= 4;
            for (int i = y; i < y+2; i++){
                for (int j = mr; j < mr+2; j++)
                    mp[i][j] = 1;
                
                rd[i] = c - mr - 2;
            }

            break;

        case 'D':
            if (rd[y] < 1 || rd[y+1] < 3){
                p++;
                break;
            }

            s -= 4;
            mp[y][c-rd[y+1]+2] = 1;
            mp[y+1][c-rd[y+1]] = 1;
            mp[y+1][c-rd[y+1]+1] = 1;
            mp[y+1][c-rd[y+1]+2] = 1;
            break;

        default:
            break;
        }

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cout << mp[i][j] << ' ';
            }
            cout << '\n';
        }
        // cout << '\n';
        // for (int i = 0; i < r; i++){
        //     cout << rd[i] << '\n';
        // }
    }

    cout << s << ' ' << p;
}