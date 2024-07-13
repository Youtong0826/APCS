#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, lx, ly, ld = 0, d = 0, r = 0, l = 0, t = 0;

    cin >> n;
    cin >> lx >> ly;
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        if (x > lx)
            d = 0;

        else if (y < ly)
            d = 1;

        else if (x < lx)
            d = 2;

        else
            d = 3;

        int dir = (d-ld+4) % 4;
        if (dir == 1)
            r++;

        else if (dir == 2)
            t++;

        else if (dir == 3)
            l++;

        lx = x, ly = y;
        ld = d;
    }

    cout << l << ' ' << r << ' ' << t;
}