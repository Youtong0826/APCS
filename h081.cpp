#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, y, f = 1, x, total = 0;
    cin >> n >> d >> x;
    n--;
    while (n--){
        cin >> y;
        if (f && y >= x+d){
            total += y - x;
            x = y;
            f = 0;
        }

        else if (!f && y <= x-d){
            x = y;
            f = 1;
        }
    }
    cout << total;
}