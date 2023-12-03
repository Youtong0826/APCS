#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n, a, l = 0, r = 0, maxN = INT_MIN, minN = INT_MAX;
    cin >> x >> n;

    for (int i = 0; i < n; i++){
        cin >> a;
        
        if (a > x) 
            r++;
        else
            l++;
        
        maxN = max(maxN, a);
        minN = min(minN, a);
    }

    cout << ((l > r)? l: r) << ' ' << ((l > r)? minN: maxN);
}