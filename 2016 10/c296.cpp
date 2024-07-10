#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int m, int k){
    int sum = 0;
    for (int i = n-k+1; i <= n; i++){
        sum = (sum+m) % i;
    }
    return sum+1;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    cout << josephus(n, m, k) << '\n';
}