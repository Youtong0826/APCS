#include <bits/stdc++.h>
using namespace std;

bool mp[1000][27];

int main(){
    int n, count, ans = INT_MAX;
    string s, ans_str;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        count = 0;
        for (auto c: s){
            if (!mp[i][c-'A']){
                mp[i][c-'A'] = 1;
                count++;
            }
        }

        if (count < ans) {
            ans = count, ans_str = s;
        }

        else if (count == ans) {
            ans_str = min(ans_str, s);
        }
        
    }

    cout << ans_str << '\n';
}