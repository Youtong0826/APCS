#include <bits/stdc++.h>
using namespace std;

int m[21];

int main(){
    int n, minX = INT_MAX, maxY = INT_MIN; 
    // 宣告變數，minX 意旨最低的及格分數，minY 意旨最高的不及格分數
    cin >> n; // 讀取學生人數
    for (int i = 0; i < n; i++){
        cin >> m[i];
        if (m[i] >= 60) // 如果大於等於 60
            minX = min(minX, m[i]); // 取較小值
        
        else // 否則
            maxY = max(maxY, m[i]); // 取較大值
    }

    sort(m, m+n); // 對 m 由小到大排序
    for (int i = 0; i < n; i++) // 輸出分數
        cout << m[i] << ' ';
    
    cout << '\n';
    if (minX == INT_MAX) // 如果沒有及格的最小值
        cout << maxY << '\n' << "worst case";

    else if (maxY == INT_MIN) // 如果沒有不及格的最大值
        cout << "best case" << '\n' << minX;
    
    else // 否則輸出及格最小值和不及格最大值
        cout << maxY << '\n' << minX << '\n';
}