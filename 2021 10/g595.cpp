#include <bits/stdc++.h>
using namespace std;

int h[100];

int main(){
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    if (!h[1])
        m += h[2];

    if (!h[n])
        m += h[n-1];

    for (int i = 2; i <= n-1; i++){
        if (h[i] == 0)
            m += min(h[i+1], h[i-1]);
    }

    cout << m;
}