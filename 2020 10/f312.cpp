#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, b1, b2, c1, c2, n, y1, y2, ans = INT_MIN;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;

    for (int x1 = 0; x1 <= n; x1++){
        int x2 = n-x1;
        y1 = a1 * x1 * x1 + b1 * x1 + c1;
        y2 = a2 * x2 * x2 + b2 * x2 + c2;
        ans = max(ans, y1+y2);
    }

    cout << ans << '\n';
}