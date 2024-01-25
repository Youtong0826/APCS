#include <bits/stdc++.h>
using namespace std;

// 0 0 1 0001
// 1 0 2 0010
// 0 1 3 0011
// 2 0 4 0100
// 1 1 5 0101
// 1 1 6 0110
// 0 2 7 0111
// 3 0 8 1000
// 2 1 9
// 2 1 10
// 1 2 11
// 2 1 12
// 1 2 13
// 1 2 14
// 0 3 15
// 4 0 16
// 3 1 17
// 3 1 18
// 2 2 19
// 3 1
// 2 2
// 1 3
// 3 1
// 2 2
int n, p;
pair<int, int> dfs(int idx, int left, int right){
    if (p == idx)
        return {left, right};
    
    if (p < idx)
        return {0, 0};
    
    return max(dfs(idx*2, left+1, right), dfs(idx*2+1, left, right+1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        cin >> p;
        auto d = dfs(1, 0, 0);
        cout << d.first << ' ' << d.second << '\n';
    }
}