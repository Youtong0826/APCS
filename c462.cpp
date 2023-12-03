#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); //優化IO
    cin.tie(0); cout.tie(0);

    int k, n = 1, a = 0, ans = 0; // n 為紀錄連續子字串的長度 a 為串接各字串後的長度 ans 為比對所有長度後的最大長度
    string s;
    cin >> k >> s;

    
    bool lt = !isupper(s[0]); // 上個子字串的大小寫 (就像 aa BB aa 為 0 1 0)

    for (unsigned i = 1; i < s.size(); i++){ // 遍歷字串
        bool last = isupper(s[i-1]); // 上個字元的大小寫 (大寫為1 小寫為 0)
        bool now = isupper(s[i]); // 該字元的大小寫
        if (last == now){ // 如果跟上個字元相等
            if (n < k) 
                n++;
            
            else if (a > k){ // 當 n >= k 也就是超出k的大小時 如果子字串的數量大於 1(子字串的數量 = a / k, 1 = k / k)
                n = k;
                a = k;
            }

        }
        
        else{ // 如果跟上個字元不相等
            if (n != k) // 如果 n != k 的話就代表不符合 所以 a = 0
                a = 0;
            
            n = 1; // 重設 n
            lt = last; // 重設 lt
        }

        if (n == k && lt != now){ // 如果子字串長度跟k相等且這個子字串的大小寫不等於上個子字串 代表符合 所以長度增加 並重設 lt
            a += k;
            lt = now;
        }
        
        ans = max(ans, a); // 找出最大的 a
    }

    cout << ((s.size() == 1)? 1: ans); // s 的長度有可能為 1
}