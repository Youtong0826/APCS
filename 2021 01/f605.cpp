#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d, g = 0, total = 0;
    cin >> n >> d;
    while (n--){
        int c, a = INT_MAX , b = INT_MIN, sum = 0;
        for(int i = 0; i < 3; i++){
            cin >> c;
            sum +=  c;
            a = min(a, c);
            b = max(b, c);
        }

        if (b - a >= d){
            g++;
            total += sum/3;
        }
    }

    cout << g << ' ' << total;
}