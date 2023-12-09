//待解
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<char> d;
    string s, ms;
    while (cin >> n){
        int t = INT_MAX;
        d.clear();
        while (n--){
            cin >> s;
            for (auto i: s)
                d.insert(i);

            int size = d.size();
            if(size < t){
                ms = s;
                t = size;
            }

            else if (size == t && ms.compare(s) == 1){
                ms = s;
            }
        }
        cout << ms << '\n';
    }
}