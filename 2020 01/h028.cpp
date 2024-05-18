#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) emplace_back(x)
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define Youtong ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int maxn = 1e5+5;
int id[maxn], h[maxn];
stack<int> stk;

signed main(){
    int n, L, total = 0, height = INT_MIN;
    cin >> n >> L;

    for (int i = 1; i <= n; i++)
        cin >> id[i];

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    h[0] = h[n+1] = INT_MAX;
    id[n+1] = L;
    stk.push(0);
    for (int i = 0; i <= n; i++){
        if (id[i]-h[i] >= id[stk.top()] || id[i]+h[i] <= id[i+1]){
            total++;
            height = max(height, h[i]);
            while (stk.size() && id[stk.top()]+h[stk.top()] <= id[i+1]){
                total++;
                height = max(height, h[stk.top()]);
                stk.pop();
            }
        }
        else
            stk.push(i);
    }

    cout << total << '\n' << height;
}