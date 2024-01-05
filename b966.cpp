#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
#define l first
#define r second

priority_queue<pr, vector<pr>, greater<pr>> temp;
vector<pair<int, int>> nums;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    while (n--){
        cin >> a >> b;
        temp.push(make_pair(a, b));
    }

    int max = temp.top().l, result = 0;
    while(!temp.empty()) {
        pr cur = temp.top();
        temp.pop();
        if (cur.r <= max)
            continue;

        result += (cur.l <= max)? (cur.r - max): (cur.r - cur.l);
        max = cur.r;
    }

    cout << result << '\n';
}