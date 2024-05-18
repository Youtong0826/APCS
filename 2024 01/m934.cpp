#include <bits/stdc++.h>
#define Youtong ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

// 區間dp
const int maxn = 101;
int arr[maxn], pre[maxn], dp[maxn][maxn];

int main(){
    Youtong;
    int n;
    cin >> n;
    memset(dp,  10000, sizeof(dp));
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = arr[i] + pre[i-1];
        dp[i][i] = 0;
    }    

    for (int len = 2; len <= n; len++){
        for (int i = 1; i+len-1 <= n; i++){
            int j = i+len-1;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+abs((pre[j]-pre[k])-(pre[k]-pre[i-1])));
            }
        }
    }
    
    cout << dp[1][n] << '\n';
}