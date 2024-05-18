// 2 4 1 3 7 6 9
// pre: 0 2 6 7 10 17 23 32
// suf: 32 30 26 25 22 15 9
// 二次前綴和: 可得距離越遠被加越多次的效果
// 2pre: 0 2 8 15 25 42 55 84
// 2suf: 159 127 97 71 46 24 9 0
// 左區間和: 2   8  15 25 42
// 右區間和: 97  71 46 24 9

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 5e4+10;
int n, k, p[mx], pre[mx], suf[mx];

int f(int l, int r, int t){
    if (r-l < 2 || t > k)
        return 0;

    pre[l] = 0, suf[r] = 0;
    int delta = 0; //用來存第一次前綴和與後綴和的值
    for (int i = l+1; i <= r; i++){
        delta += p[i-1];
        pre[i] = pre[i-1] + delta;
    }

    delta = 0;
    for (int i = r-1; i >= l; i--){
        delta += p[i+1];
        suf[i] = suf[i+1] + delta;
    }

    int mid = 0, mn = INT64_MAX;
    for (int i = l+1; i <= r-1; i++){
        int d = abs(suf[i]-pre[i]);
        if (d < mn){
            mn = d;
            mid = i; 
        }
    }
    
    return p[mid] + f(l, mid-1, t+1) + f(mid+1, r, t+1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << f(0, n-1, 1);
}