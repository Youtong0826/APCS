#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(){
    int x, y, z;
    string c;
    cin >> c;
    if (c == "f"){
        x = f();
        return x*2 -3;
    }

    if (c == "g"){
        x = f();
        y = f();
        return x*2+y-7;
    }

    if (c == "h"){
        x = f();
        y = f();
        z = f();
        return x*3-y*2+z;
    }

    return stoi(c);
}

signed main(){
}