#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, len = 1, ans = 1;
    cin >> n >> x;
    for (int i = 1; i < n; i++){
        cin >> y;
        if (y < x)
            len++;

        else 
            len = 1;

        ans = max(ans, len);
        x = y;
    }

    cout << ans;
}