#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m = 0;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    for (int i = 0; i < n-1; i++){
        if (h[i+1] == 0 && i == n-2)
            m += h[i];

        else if (h[i] == 0)
            m += (i == 0)? h[1]: min(h[i+1], h[i-1]);
    }

    cout << m;
}