#include <bits/stdc++.h>
#define int long long
#define Youtong ios_base::sync_with_stdio(0); cin.tie(0); cout.tie()
using namespace std;

set<int> stick;
vector<pair<int, int>> op;
signed main(){
    Youtong;
    int n, l, ans = 0;
    cin >> n >> l;
    stick.insert(0);
    stick.insert(l);

    op.resize(n);
    for (auto &[x, y]: op)
        cin >> y >> x;

    sort(op.begin(), op.end());
    for (auto [x, y]: op){
        auto R = stick.lower_bound(y);
        auto L = prev(R, 1);
        ans += *R-*L;
        stick.insert(y);
    }

    cout << ans;
}