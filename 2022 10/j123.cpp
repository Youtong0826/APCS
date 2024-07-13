#include <bits/stdc++.h>
using namespace std;

bool mp[35][55];
int rd[35];

int main(){
    int r, c, n, y, p = 0, mr;

    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
        rd[i] = c;

    char a;
    int s = r * c;
    while (n--){
        cin >> a >> y;
        switch (a){
        case 'A':
            if (rd[y] < 1 || rd[y+1] < 1 || rd[y+2] < 1 || rd[y+3] < 1){
                p++;
                break;
            }

            mr = max({c-rd[y], c-rd[y+1], c-rd[y+2], c-rd[y+3]});
            s -= 4;
            for (int i = y; i < y+4; i++){
                for (int j = mr; j < mr+1; j++)
                    mp[i][j] = 1;

                rd[i] = c - mr - 1;
            }
            break;
        
        case 'B':
            if (rd[y] < 3) {
                p++;
                break;
            }

            s -= 3;
            for (int i = c-rd[y]; i < c-rd[y]+3; i++)
                mp[y][i] = 1;
            
            rd[y] -= 3;
            break;

        case 'C':
            if (rd[y] < 2 || rd[y+1] < 2){
                p++;
                break;
            }

            mr = max(c-rd[y], c-rd[y+1]);
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
            mr = c-rd[y+1];
            for (mr = c-rd[y+1]; mr < c; mr++) {
                if (!mp[y][mr+2])
                    break;
            }
            mp[y][mr+2] = 1;
            for (int i = y; i < y+2; i++)
                rd[i] = c - mr - 3;

            for (int i = mr; i < mr+3; i++)
                mp[y+1][i] = 1;
            
            break;

        case 'E':
            if (rd[y] < 1 || rd[y+1] < 2 || rd[y+2] < 2){
                p++;
                break;
            }
            
            s -= 5;
            mr = c-rd[y+1];
            for (mr = c-rd[y+1]; mr < c; mr++) {
                if (!mp[y][mr+1])
                    break;
            }

            mp[y][mr+1] = 1;

            for (int i = y; i < y+4; i++)
                rd[i] = c - mr - 2;

            for (int i = y+1; i < y+3; i++){
                for (int j = mr; j < mr+2; j++)
                    mp[i][j] = 1;
            }
            break;

        default:
            break;
        }

        // for (int i = 0; i < r; i++){
        //     for (int j = 0; j < c; j++){
        //         cout << mp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int i = 0; i < r; i++){
        //     cout << rd[i] << '\n';
        // }
    }

    cout << s << ' ' << p;
}