#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n, t = 0;
    cin >> a >> b >> n;
    while (n--){
        int m = 1, ta = 0, tb = 0;
        while (m){
            cin >> m;
            if(m == a)
                ta++;

            else if (m == b)
                tb++;

            else if (m == -a)
                ta--;

            else if (m == -b)
                tb--;
        }

        if (ta > 0 && tb > 0)
            t++;
    }

    cout << t;
}