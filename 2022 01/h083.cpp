#include <bits/stdc++.h>
#define Youtong ios_base::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

unordered_set<string> st;

int main(){
    Youtong;
    string s;
    int m, ans = 0;
    cin >> m;
    while (m--){
        cin >> s;
        st.insert(s);
    }

    for (auto it = st.begin(); it != st.end(); it++){
        auto s = *it;
        if (!st.empty()){
            for (int i = 1; i <= s.size()/2; i++){
                string t1 = s.substr(0, i), t2 = s.substr(s.size()-i, s.size());
                cout << t1 << ' ' << t2 << ' ' << s.substr(i, s.size()-i-i) << '\n';
                
                if (t1 != t2)
                    continue;
                
                
                auto it = st.find(s.substr(i, s.size()-i-i));
                if (it != st.end()){
                    ans++;
                }
            }
        }
    }
    
    cout << ans;
}