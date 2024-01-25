#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
vector<vector<int>> node;
vector<int> dis;
unordered_set<int> st;

void dfs(int id, int dep){
    if (!node[id].size()){
        dis[id] = dep;
        return;
    }

    for (auto it:node[id]){
        dfs(it, dep+1);
        dis[id] = max(dis[id], dis[it]);
    }

    ans += dis[id]-dep;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, p;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        st.insert(i);

    node.assign(n+1, {});
    dis.assign(n+1, 0);
    for (int i = 1; i <= n; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> p;
            node[i].push_back(p);
            st.erase(p);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for (int j = 0; j < node[i].size(); j++){
    //         cout << node[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    dfs(*st.begin(), 0);
    cout << *st.begin() << '\n' << ans;
}