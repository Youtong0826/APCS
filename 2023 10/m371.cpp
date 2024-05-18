#include <bits/stdc++.h>
using namespace std;

int mp[25][40];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }

    for (int t = 0; t < n*m; t++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mp[i][j] < 1)
                    continue;

                for (int k = j+1; k < m; k++){
                    if(mp[i][k] == -1)
                        continue;

                    if (mp[i][j] == mp[i][k]){ 
                        sum += mp[i][k];
                        mp[i][k] = mp[i][j] = -1;
                        break;
                    }

                    else
                        break;
                }
                for (int k = i+1; k < n; k++){
                    if(mp[k][j] == -1)
                        continue;

                    if (mp[i][j] == mp[k][j]){ 
                        sum += mp[k][j];
                        mp[k][j] = mp[i][j] = -1;
                        break;
                    }

                    else
                        break;
                }
            }
        }
    }

    cout << sum;
}