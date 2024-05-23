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

vector<int> m, x, y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, xl = -1, yl = -1;
    cin >> n;
    
    m.resize(n);
    for (auto &e: m){
        cin >> e;
        if (e >= 60)
            x.push_back(e);
        
        else 
            y.push_back(e);
    }

    sort(m.begin(), m.end());
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    for(auto i: m)
        cout << i << ' ';

    cout << '\n';
    if (x.empty())
        cout << y.back() << '\n' << "worst case";

    else if (y.empty())
        cout << "best case" << '\n' << x[0];
    
    else
        cout << y.back() << '\n' << x[0] << '\n';
}
