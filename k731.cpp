// -> 解題思路
// 定義方向 d
// d = 0 向右 東 
// d = 1 向下 南
// d = 2 向左 西
// d = 3 向上 北
// 起始點 (0, 0) 初始方向向右 (d = 0)
// 假設 x+1  方向不變
// 假設 y-1  方向改變 (0 -> 1) 右轉
// 假設 x-1  方向改變 (0 -> 2) 迴轉
// 假設 y+1  方向改變 (0 -> 3) 左轉
// 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, lx, ly, ld = 0, d = 0, r = 0, l = 0, t = 0;

    cin >> n;
    cin >> lx >> ly;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        if (x > lx)
            d = 0;

        else if (y < ly)
            d = 1;

        else if (x < lx)
            d = 2;

        else
            d = 3;

        int dir = (d-ld+4) % 4;
        if (dir == 1)
            r++;

        else if (dir == 2)
            t++;

        else if (dir == 3)
            l++;

        lx = x, ly = y;
        ld = d;
    }

    cout << l << ' ' << r << ' ' << t;
}