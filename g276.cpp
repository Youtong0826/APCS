#include <bits/stdc++.h>
using namespace std;

int n, m, k, mp[105][105], val[505][5], dn = 0;
bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            mp[i][j] = 0;
    }

    for (int i = 0; i < k; i++){
        val[i][4] = 1;
        cin >> val[i][0] >> val[i][1] >> val[i][2] >> val[i][3];// r c s t
    }

    int t = 5;
    while (t--){
        if(dn == k)
            break;

        for (int i = 0; i < k; i++){
            if (!val[i][4]){
                dn++;
                continue;
            }

            mp[val[i][0]][val[i][1]] = 2;
            val[i][0] = val[i][0] + val[i][2];
            val[i][1] += val[i][3];
        }
        
        for (int i = 0; i < k; i++){
            if(mp[val[i][0]][val[i][1]] == 2 || !in(val[i][0], val[i][1]))
                val[i][4] = 0;
            
            else
                mp[val[i][0]][val[i][1]] = 1;
        }
        
        cout << "\n\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << mp[i][j] << ' ';
            }
            cout << "\n";
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 2)
                ans++;
        }
    }

    cout << ans;
}