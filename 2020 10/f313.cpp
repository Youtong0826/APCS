// 範例1
// R=2, C=3, k=4, m=1
//10 2 -1 -> 7 4 -1
//5 -1 2     6 -1 2
//map[0][0] 10 周圍有兩座可遷移城市
//10/k = 2, 10 - 2*2 = 6
//!今天過後隔壁的 2 跟 5 分別會+2
//map[0][1] 2 周圍只有一座可遷移城市
//2/k = 0 無遷移人口
//map[0][2] -1 非城市
//map[1][0] 5 周圍只有一座可遷移人口
//5/k = 1 5-1*1 = 4 隔壁的10 +1
//map[1][1] -1 非城市
//map[1][2] 周圍無可遷移城市
// 第一天過後 10 - 4 +1, 2+2, 5-1+2
// 結果 7, 4, 6

#include <bits/stdc++.h>
using namespace std;

int r, c, k, m;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool in(int x, int y){
    return x >= 0 && x < r && y >= 0 && y < c;
}

int main(){
    cin >> r >> c >> k >> m;
    int map[r][c], temp[r][c];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> map[i][j];
            temp[i][j] = map[i][j];
        }
    }
    
    int mn, nn;
    while (m--){
        mn = INT_MIN, nn = INT_MAX;
        for(int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (map[i][j] != -1){
                    for (int l = 0; l < 4; l++){
                        if (in(i+dx[l], j+dy[l]) && map[i+dx[l]][j+dy[l]] != -1){
                            temp[i+dx[l]][j+dy[l]] += map[i][j]/k;
                            temp[i][j] -= map[i][j]/k;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                map[i][j] = temp[i][j];
                if (map[i][j] != -1){
                    nn = min(map[i][j], nn);
                    mn = max(map[i][j], mn);
                }
            }
        }
    }

    cout << nn << '\n' << mn;
}

