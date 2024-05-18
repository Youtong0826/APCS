// 流量的計算方法
// 0 0 1 0
// Q[0][j];

#include <bits/stdc++.h>
using namespace std;

int n, m, k, l;
int Q[55][55], city[55][55], C[55];

int calc(){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            city[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            city[C[i]][j] += Q[i][j];
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++){
            if (i == j)
                ans += city[i][j];
            else
            {
                if (city[i][j] <= 1000)
                    ans += city[i][j] * 3;
                else
                    ans += 3000 + (city[i][j] - 1000) * 2;
            }
        }
    return ans;
}

int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> Q[i][j];
    }

    int ans = INT_MAX;
    while (k--){
        for (int i = 0; i < n; i++)
            cin >> C[i];

        ans = min(ans, calc());
    }

    cout << ans;
}