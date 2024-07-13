#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first 
#define s second 
using namespace std;

vector<pii> vt;
bool cmp(pii a, pii b){
     return a.f * a.f + a.s * a.s > b.f * b.f + b.s * b.s;
}

int main(){
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        vt.push_back({x, y});
    }

    sort(vt.begin(), vt.end(), cmp);
    cout << vt[1].f << ' ' << vt[1].s << '\n';
}