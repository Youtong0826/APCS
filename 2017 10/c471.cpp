#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<LL, LL> 

vector<P> dat;
vector<LL> stack;

bool cmp(P x, P y){
    return x.first * y.second < y.first * x.second;
}

int main(){
    int n, pre[100010];
    cin >> n;
    dat.assign(n, {0, 0});

    for (int i = 0; i < n; i++)
        cin >> dat[i].first;

    for (int i = 0; i < n; i++)
        cin >> dat[i].second;

    sort(dat.begin(), dat.end(), cmp);

    pre[0] = dat[0].first;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i-1] + dat[i].first;

    LL cost = 0;
    for (int i = 1; i < n; i++){
        cost += dat[i].second * pre[i-1];
    }
    
    cout << cost << '\n';
}