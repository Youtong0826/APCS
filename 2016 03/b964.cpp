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

vector<int> m;

int main(){
    int n, minX = INT_MAX, maxY = INT_MIN;
    cin >> n;
    
    m.resize(n);
    for (auto &e: m){
        cin >> e;
        if (e >= 60)
            minX = min(minX, e);
        
        else 
            maxY = max(maxY, e);
    }

    sort(m.begin(), m.end());
    
    for(auto i: m)
        cout << i << ' ';

    cout << '\n';

    if (minX == INT_MAX)
        cout << maxY << '\n' << "worst case";

    else if (maxY == INT_MIN)
        cout << "best case" << '\n' << minX;
    
    else
        cout << maxY << '\n' << minX << '\n';
}

