#include <bits/stdc++.h>
#define int long long 
using namespace std;

vector<int> diff, dtime, sec;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    diff.assign(n+2, 0);
    while (m--){
        cin >> a >> b >> c;
        diff[a] += c;
        diff[b+1] -= c;
    }
    
    int num = 0;
    for (auto i: diff){
        num += i;
        dtime.push_back(num);
    }

    int s;
    while(n--){
        cin >> s;
        sec.push_back(s);
    }

    sort(dtime.rbegin(), dtime.rend());
    sort(sec.begin(), sec.end());
    int total = 0;
    for (int i = 0; i < dtime.size(); i++)
        total += dtime[i] * sec[i];

    cout << total;
}