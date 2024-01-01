#include <bits/stdc++.h>
using namespace std;

int n;
long long sum = 0;
void dfs(int last){
    cin >> n;
    if (!n)
        return;

    int now = n;
    if (last)
        sum += abs(now-last);
    
    if(n % 2){
        dfs(now);
        dfs(now);
        dfs(now);
    }
    else{
        dfs(now);
        dfs(now);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dfs(0);
    cout << sum;
}