//待解
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> r;
    vector<pair<string, int>> d;
    int n, t;
    string s;

    cin >> n;
    while (n--){
        cin >> s;
        for (auto m:s){
            if(!count(r.begin(), r.end(), m)){
                r.push_back(m);
                t++;
            }
        }

        if(count(r.begin(), r.end(), ' '))
            t--;

        auto st = make_pair(s, t);
        d.push_back(st);
    }

    sort(d.begin(), d.end(), [](pair<string, int> x, pair<string, int> y){return x.second < y.second;});
    remove_if(d.begin(), d.end(), [d](pair<string, int> x){return x.second != d[0].second;});
    sort(d.begin(), d.end(), [](pair<string, int> x, pair<string, int> y){return x.first < y.first;});

    cout << d[0].first << '\n';
}