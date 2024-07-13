#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int k, c = 1; 
    string s;
    cin >> k >> s;

    if (s.size() == 1){
        cout << 1;
        return 0;
    }

    bool last = isupper(s[0]), now;
    for (int i = 1; i < s.size(); i++){ 
        now = isupper(s[i]); 
        if (last == now) 
            c++;
        else {
            v.push_back(c);
            c = 1;
        }
        last = now;
    }

    v.push_back(c);

    int l = 0, r = 0, len = 0, h = -1, e = -1;
    while (l < v.size() && r < v.size()) {
        // cout << "continue..." << '\n';
        if (v[l] != k) {
            l++, r++;
            continue;
        }

        if (v[r] != k) {
            l = r;
            continue;
        }

        // cout << l << ' ' << r << '\n';
        
        if (r-l+1 > len) {
            len = r-l+1;
            h = l;
            e = r;
        }

        r++;
    }
    
    if (h >= 0 && v[h-1] >= k)
        len++;

    if (e <= v.size()-1 && v[e+1] >= k)
        len++;

    cout << len*k;
}

