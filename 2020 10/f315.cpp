#include <bits/stdc++.h>
#define int long long
#define lowbit(x) x & -x
using namespace std;

const int maxn = 1e5+2;
int n, x, bit[maxn*2];
vector<vector<int>> a;

void update(int x, int v){
    for (int i = x; i <= 2*n; i += lowbit(i))
        bit[i] += v;
}

int query(int x){
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += bit[i];

    return ans;
}

signed main(){
    cin >> n;
    a.assign(n+1, {});
    for (int i = 1; i <= n*2; i++){
        cin >> x;
        a[x].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        // cout << a[i][0] << ' ' << a[i][1] << '\n';
        // cout << query(a[i][1]) << ' ' << query(a[i][0]-1) << '\n';
        ans += query(a[i][1]) - query(a[i][0]-1);
        update(a[i][0], 1);
        update(a[i][1], 1);
    }

    cout << ans << '\n';
}