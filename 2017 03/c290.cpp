#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string x;
    int a = 0, b = 0;
    cin >> x;
    for (int i = 0; x[i] != '\0'; i++){
        if (i % 2)
            b += (int)(x[i]-'0');
        else
            a += (int)(x[i]-'0');
    }
    cout << abs(a-b);
}