// min(dp[i+1][j], dp[i][j+1]);

#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
bool jump[25];
vector<long long> nums;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> dp[i][j];
            
    long long ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            ans += (dp[i+1][j] <= dp[i][j+1])? dp[i+1][j]: dp[i][j+1];
        
    cout << ans;
}