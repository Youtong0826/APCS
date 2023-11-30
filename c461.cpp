#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b, c;
    bool f = 1;
    cin >> a >> b >> c;

    if((a && b) == c){
        cout << "AND" << '\n';
        f = 0;
    }

    if((a || b) == c){
        cout << "OR" << '\n';
        f = 0;
    }

    if((a && !b || !a && b) == c){
        cout << "XOR";
        f = 0;
    }

    if (f)
        cout << "IMPOSSIBLE";
}