#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define l first
#define r second

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n;
    while (n--){
        cin >> a >> b;
        pq.push({a, b});
    }

    int mr = -1, result = 0;
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        if (t.r <= mr )
            continue;

        result += (t.l <= mr )? (t.r - mr): (t.r - t.l);
        mr = t.r;
    }

    cout << result << '\n';
}