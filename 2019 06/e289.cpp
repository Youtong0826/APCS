#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
string arr[maxn];
unordered_map<string, int> mp;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n, count = 0;
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    for (int i = 0; i < m; i++){
        if (!mp[arr[i]])
            count++;
            
        mp[arr[i]]++;
    }
    
    int ans = 0;
    if (count == m)
        ans++;
    
    for (int i = m; i < n; i++){
        if (!mp[arr[i]])
            count++;
            
        mp[arr[i]]++;
        
        if (mp[arr[i-m]] == 1)
            count--;
        
        mp[arr[i-m]]--;
        
        if(count == m)
            ans++;
    }
    
    cout << ans;
}