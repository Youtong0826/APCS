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

int f(int left, int right, int level){
    if (right - left < 2 || level > k)
        return 0;

    pre[left] = 0, suf[right] = 0;
    int delta = 0; //用來存第一次前綴和與後綴和的值
    for (int i = left+1; i <= right; i++){
        delta += p[i-1];
        pre[i] = pre[i-1] + delta;
    }

    delta = 0;
    for (int i = right-1; i >= left; i--){
        delta += p[i+1];
        suf[i] = suf[i+1] + delta;
    }

    int mn = INT64_MAX;
    int mi = 0;
    for (int i = left+1; i <= right-1; i++){
        int d = abs(suf[i]-pre[i]);
        if (d < mn){
            mn = d;
            mi = i; 
        }
    }
    
    return p[mi] + f(left, mi-1, level+1) + f(mi+1, right, level+1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << f(0, n-1, 1);
}