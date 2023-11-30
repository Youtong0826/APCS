#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x1, x2, y1, y2, a = INT_MIN, b = INT_MAX;

    cin >> n;
    int dn = n;

    while (n--){
        x2 = x1;
        y2 = y1;
    
        cin >> x1 >> y1;
        if(n+1 != dn){
            a = max(a, abs(x2-x1) + abs(y2-y1));
            b = min(b, abs(x2-x1) + abs(y2-y1));
        }
    }

    cout << a << ' ' << b;
}