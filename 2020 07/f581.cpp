#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5+5;
int pre[maxn];

int main(){
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> pre[i];
        pre[i+n] = pre[i];
    }
    
    for (int i = 1; i < n*2; i++)
        pre[i] += pre[i-1];
           
    int idx = 0;       
    while (m--) {
        cin >> q;
        if (idx)
            q += pre[idx-1];
            
        idx = (lower_bound(pre, pre+n*2, q) - pre + 1) % n; 
    }
    
    cout << idx << '\n';
}