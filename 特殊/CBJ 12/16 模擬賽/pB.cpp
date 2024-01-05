#include <bits/stdc++.h>
using namespace std;

string key[3] = {
    "Q0W0E0R0T0Y0U0I0O0P",
    "0A0S0D0F0G0H0J0K0L",
    "00Z0X0C0V0B0N0M"
};

bool in(int x, int y){
    if (x > 2 || x < 0 || key[x][y] == '0')
        return 0;

    if (x == 0)
        return y >= 0 && y < 19;

    if (x == 1)
        return y >= 0 && y < 18;

    if (x == 2)
        return y >= 0 && y < 15;

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, c, x, y;
    char f;
    cin >> n >> f;
    for (int i = 0; i < 3; i++){
        int it = key[i].find(f);
        if (it != -1){
            x = i;
            y = it;
        }
    }

    // cout << x << ' ' << y;

    // 1 左 2 左上 3 右上 4 右 5 左下 6 右下
    while (n--){
        cin >> c;
        if (c == 1){
            cin >> c;
            switch (c){
            case 1:
                if (in(x, y-2))
                    y-=2;

                break;

            case 2:
                if (in(x-1, y-1)){
                    x--;
                    y--;
                }
                break;

            case 3:
                if (in(x-1, y+1)){
                    x--;
                    y++;
                }
                break;

            case 4:
                if (in(x, y+2))
                    y+=2;

                break;
            
            case 5:
                if (in(x+1, y-1)){
                    x++;
                    y--;
                }
                break;
            
            case 6:
                if (in(x+1, y+1)){
                    x++;
                    y++;
                }
                break;
            }
        }
        else
            cout << key[x][y];
    }
}