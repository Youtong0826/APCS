// 第一行為學生人數
// 第二行為各學生的成績
//
// -> 解題思路:
// 將分數>=60 設為 x 而<60 設為 y
// 並將其排序 x 找出最小值 y 找出最大值
// 如果x沒有元素 代表沒有最小的及格成績 即為 wrost case
// 如果y沒有元素 代表沒有最大的不及格成績 即為 best case

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, xl = -1, yl = -1;
    cin >> n;
    int m[n], x[n], y[n];
    
    for (int i = 0; i < n; i++){
        cin >> m[i];
        if(m[i] >= 60){
            xl++;
            x[xl] = m[i];
        }
        else {
            yl++;
            y[yl] = m[i];
        }
    }

    sort(m, m+n);
    sort(x, x+xl+1);
    sort(y, y+yl+1);

    int mx = x[0];
    int my = y[yl];

    for(auto i:m)
        cout << i << ' ';

    cout << '\n';
    if(xl == -1)
        cout << my << '\n' << "worst case";

    else if(yl == -1)
        cout << "best case" << '\n' << mx;
    
    else
        cout << my << '\n' << mx << '\n';
}