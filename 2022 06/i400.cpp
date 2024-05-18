// BCAAD 經過10110加密
// 1出現次數為奇數 所以字串前後對調 -> ADABC
// 1 C 0 CA 1 CAB 1 CABA 0 CABAD
// 因為題目給的是已經編碼過的字串 所以我們要將其解碼 過程如下
// CABAD 10110
// 0 D 1 DA 1 DAB 0 ADAB 1 ADABC 
// 1出現次數為奇數 所以字串前後對調 得原字串 BCAAD

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> e;
    string t, s;
    int n, m;

    cin >> m >> n;
    e.assign(m, "");
    for (int i = 0; i < m; i++)
        cin >> e[i];
    
    cin >> t;

    while (e.size()){
        string a = e.back();
        int b = 0;
        s = "";
        for (int i = 0; i < n; i++)
            if (a[i] == '1')
                b++;
        
        while (t.size()){
            if (a.back() == '0')
                s = t.back() + s;
            
            else
                s.push_back(t.back());
            
            t.pop_back();
            a.pop_back();
        }

        if (b % 2)
            for (int i = 0; i < n/2; i++){
                if (n % 2)
                    swap(s[i], s[n/2+i+1]);
                
                else
                    swap(s[i], s[n/2+i]);
            }
                
        e.pop_back();
        t = s;
    }

    cout << s;
}