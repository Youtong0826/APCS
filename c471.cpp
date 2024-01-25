#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<LL, LL> 

vector<P> data;
vector<LL> stack;

bool cmp(P x, P y){
    return x.first * y.second < y.first * x.second;
}

int main(){
    int n, pre[100010];
    cin >> n;
    data.assign(n, {0, 0});

    for (int i = 0; i < n; i++)
        cin >> data[i].first;

    for (int i = 0; i < n; i++)
        cin >> data[i].second;

    sort(data.begin(), data.end(), cmp);

    pre[0] = data[0].first;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i-1] + data[i].first;

    LL cost = 0;
    for (int i = 1; i < n; i++){
        cost += data[i].second * pre[i-1];
    }
    
    cout << cost << '\n';
}