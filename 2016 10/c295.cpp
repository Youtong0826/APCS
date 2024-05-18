#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, num, sum = 0, f = 1;
    vector<int> nk, out;

    cin >> n >> m;
    nk.assign(n, 0);
    for (int i = 0; i < n; i++){
        int a = INT_MIN;
        for (int j = 0; j < m; j++){
            cin >> num;
            a = max(a, num);
        }
        sum += a;
        nk[i] = a;
    }

    cout << sum << '\n';
    for (auto i:nk)
        if (sum % i == 0)
            out.push_back(i);
        
    
    if (out.empty())
        cout << -1;
        
    else{
        cout << out[0];
        for (int i = 1; i < out.size(); i++)
            cout << ' ' << out[i];
    }
        
}