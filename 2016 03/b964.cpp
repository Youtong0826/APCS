#include <bits/stdc++.h>
using namespace std;
int m[21];
int main(){
    int n, minX = INT_MAX, maxY = INT_MIN; 
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m[i];
        if (m[i] >= 60) 
            minX = min(minX, m[i]); 
        
        else 
            maxY = max(maxY, m[i]);
    }

    sort(m, m+n); // 對 m 由小到大排序
    for (int i = 0; i < n; i++) 
        cout << m[i] << ' ';
    
    cout << '\n';
    if (minX == INT_MAX) 
        cout << maxY << '\n' << "worst case";

    else if (maxY == INT_MIN) 
        cout << "best case" << '\n' << minX;
    
    else 
        cout << maxY << '\n' << minX << '\n';
}