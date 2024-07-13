#include <bits/stdc++.h>
using namespace std;

int n, m, mp[55][55];
vector<pair<int, int>> pt;

bool in(int x, int y){
    return x < n && x >= 0 && y < m && y >= 0;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x = mp[i][j], sum = 0;
            for (int k = i-x; k <= i+x; k++){
                for (int q = j-x; q <= j+x; q++){
                    if (in(k, q) && (abs(i-k)+abs(j-q)) <= x){                
                        sum += mp[k][q];
                    }
                }
            }
            if (sum % 10 == x){
                pt.push_back({i, j});
            }
        }
    }

    cout << pt.size() << '\n';
    for (int i = 0; i < pt.size(); i++)
        cout << pt[i].first << ' ' << pt[i].second << '\n';
}