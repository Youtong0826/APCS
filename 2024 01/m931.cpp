#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<pii> vt;

int main(){
    int n;
    cin >> n;
    vt.resize(n);
    for (auto &[x, y]: vt)
        cin >> x >> y;

    sort(vt.begin(), vt.end(), [](pii a, pii b){
        return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
    });
    
    cout << vt[1].first << ' ' << vt[1].second << '\n';
}