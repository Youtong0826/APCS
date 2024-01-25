#include <bits/stdc++.h>
using namespace std;

int n, p, L, R;
vector<int> s;

void bfs(int idx, int times){
    if (s[idx] < 0 || s[idx] >= n;)
        return;
    
    idx = s[idx];

    if (idx >= L){
        bfs(idx-L);
    }

    if (idx < R){
        bfs(idx+R);
    }

}

int main(){
    cin >> n >> p >> L >> R;
    s.assign(n, 0);
    for (int i = 0; i <n; i++)
        cin >> s[i];

}