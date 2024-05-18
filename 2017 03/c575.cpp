#include <bits/stdc++.h>
using namespace std;

int n, k, p[50010];

bool check(int m){
    int now = p[0]+m, d = 0;
    for (int i = 0; i < n; i++){
        
        if (p[i] > now){
            now = p[i] + m;
            d++;
        }
    }
    return d < k;
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p+n);
    int L = 0, R = p[n-1] - p[0];
    while (R - L > 1){
        int mid = (L+R)/2;
        if (check(mid))
            R = mid;

        else
            L = mid;
    }
    
    cout << R <<"\n";
    return 0;

}