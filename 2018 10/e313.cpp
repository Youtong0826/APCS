#include <bits/stdc++.h>
#define Youtong ios::sync_with_stdio(0); cin.tie(0)
#define pii pair<int, string> 
using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;
bool mp[27];

int main(){
    Youtong;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++){
        memset(mp, 0, sizeof(mp));
        cin >> s;
        int count = 0;
        for (auto c: s){
            if (!mp[c-'A']){
                mp[c-'A'] = 1;
                count++;
            }
        }

        pq.push({count, s});
    }

    cout << pq.top().second << '\n';
}