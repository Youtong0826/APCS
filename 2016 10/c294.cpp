#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int m[3] = {a, b, c};
    sort(m, m+3);

    for (auto n:m)
        cout << n << ' ';

    a = m[0];
    b = m[1];
    c = m[2];

    cout << '\n';
    if (a+b <= c){
        cout << "No";
        return 0;
    }

    int d = a*a+b*b;
    if(d < c*c)
        cout << "Obtuse";
    
    else if (d == c*c)
        cout << "Right";
    
    else
        cout << "Acute";
}