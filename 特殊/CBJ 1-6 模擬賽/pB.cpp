#include <bits/stdc++.h>
using namespace std;

char mp[505][505];

int main(){
    string s, ans = "";
    int n, k;

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];

    cin >> k >> s;
    for (int i = 0; i < k; i++){
        if (i < n){
            if (s[i] == '1')
                for (int t = 0, x = i, y = n-1; t <= i; t++, x--, y--)
                    ans += mp[x][y];
                
            else
                for (int t = 0, x = 0, y = n-i-1; t <= i; t++, x++, y++)
                    ans += mp[x][y];
        }
        else{
            if (s[i] == '1')
                for (int t = 0, x = n-1, y = 2*n-i-2; t <= n-i+1; t++, x--, y--)
                    ans += mp[x][y];
                
            else
                for (int t = 0, x = i-n+1, y = 0; t <= i; t++, x++, y++)
                    ans += mp[x][y];
        }
    }

    cout << ans;
}