#include <bits/stdc++.h>
using namespace std;

// int k, a;
// string s;
// void dfs(char last, int i){
//     if (isupper(last) == isupper(s[i]))
//         if (a != k)
//             a++;
//         else if (a == k)
//             a = k-1;
//         else
//             a = 0;
//     else
//         a++;
// }

int main(){
    int k, a = 1, ans = INT_MIN;
    string s;
    cin >> k >> s;

    char last = s[0];
    for (unsigned i = 1; i < s.size(); i++){
        cout << isupper(last) << ' ' << isupper(s[i]) << ' ';
        if (isupper(last) == isupper(s[i])){
            if (a % k != 0)
                a++;

            else if (a != k)
                a = 0;
        }
        
        else{
            if (a % k == 0)
                a++;
            
            else if (a < k)
                a--;

            else
                a = 0;
        }     

        cout << a << '\n';
        
        ans = max(ans, a);
        last = s[i];
    }
    cout << ans;
}