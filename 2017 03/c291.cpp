#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+1;
int n, f[maxn], cnt = 0;
bool vis[maxn];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> f[i];

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int idx = i;
            while (f[idx] != i) {
                vis[idx] = 1;
                idx = f[idx];
            }
            vis[idx] = 1;
            cnt++;
        }
    }

    cout << cnt << '\n';
}