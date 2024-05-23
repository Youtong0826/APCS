//矩陣轉換
//   定義 A 矩陣   -翻轉->                -旋轉->           得B
// 1(0, 0) 1(0, 1)       2(0, 0) 1(0, 1)        1(0, 0) 1(0, 1) 2(0, 2)
// 1(1, 0) 3(1, 1)       1(1, 0) 3(1, 1)        1(1, 0) 3(1, 1) 1(1, 2)
// 2(2, 0) 1(2, 1)       1(2, 0) 1(2, 1)
//
// Note: 翻轉及其反操作
// A 經過翻轉 座標改變 -> (i, j) -> (r-i-1, j)
// 其反操作為 -> (r-i-1, j) -> (i, j)
// 注意 操作次數為 r/2 因為每次執行會交換到兩條行數
//
// Note: 旋轉及其反操作
// A 經過旋轉 其座標 (i, j) -> (j, r-i-1)
// 其反操作為 (j, r-i-1) -> (i, j)
//
// 注意 這裡的 r 參數已經變為控制行的 c 參數
// 因此 要將兩者的值調換 避免r與c變成了錯誤的列數行數
// 且不能使用交換位置的方式 因為其陣列大小遭到改變

#include <bits/stdc++.h>
using namespace std;

int arr[10][10], r, c, m, ops;

void flip_back(){
    for (int i = 0; i < r/2; i++)
        for (int j = 0; j < c; j++)
            swap(arr[i][j], arr[r-i-1][j]);
}

void rotate_back(){
    int tmp[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = arr[i][j];

    swap(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = tmp[j][r-i-1];
}

int main(){
    cin >> r >> c >> m;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    
    while (m--) {
        cin >> ops;
        if (ops)
            flip_back();

        else
            rotate_back();   
    }

    cout << r << ' ' << c << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) 
              cout << arr[i][j] << ((j+1 == c)? "":" ");
        
        cout << '\n';
    }
}