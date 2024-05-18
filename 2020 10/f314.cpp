#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+3;
int mp[55][maxn];
int dp[maxn][3];

// dp[i][0] 以 i 為終點取左右的 max
// dp[i][1] 以 i 為終點從左邊走過來的最大點數
// dp[i][2] 以 i 為終點從右邊走過來的最大點數

int main(){
    int m, n, ans = 0;
    cin >> m >> n;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[j][1] = max({dp[j-1][1]+mp[i][j], dp[j][0]+mp[i][j], 0});
            // cout << dp[j][1] << ' ';
        }
        //cout << '\n';
        for (int j = n; j > 0; j--){
            dp[j][2] = max({dp[j+1][2]+mp[i][j], dp[j][0]+mp[i][j], 0});
            dp[j][0] = max(dp[j][1], dp[j][2]);
            ans = max(ans, dp[j][0]);
            // cout << dp[j][2] << ' ';//' ' << dp[j][0] << ' ';
        }
        // cout << '\n';
        // for (int j = 1; j <= n; j++)
        //     cout << dp[j][0] << ' ';
        // cout << '\n';
    }

    cout << ans << '\n';
}