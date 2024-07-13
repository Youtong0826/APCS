#include <bits/stdc++.h>
using namespace std;

int mp[25][40];

int main(){
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }

    for (int t = 0; t < n*m/2+1; t++){ // 最多只會做 n*m/2 次
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mp[i][j] == -1)
                    continue;

                for (int k = j+1; k < m; k++){ // 檢查橫排
                    if(mp[i][k] == -1)
                        continue;

                    if (mp[i][j] == mp[i][k]){ 
                        sum += mp[i][k];
                        mp[i][k] = mp[i][j] = -1;
                    }
                    break;
                }


                for (int k = i+1; k < n; k++){ // 檢查直排
                    if(mp[k][j] == -1)
                        continue;

                    if (mp[i][j] == mp[k][j]){ 
                        sum += mp[k][j];
                        mp[k][j] = mp[i][j] = -1;
                    }
                    break;
                }
            }
        }
    }

    cout << sum;
}