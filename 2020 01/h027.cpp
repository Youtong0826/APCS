#include <bits/stdc++.h>
using namespace std;

int s, t, m, n, r, sumA = 0, sumM = 0, ans = INT_MAX;
int A[10][100], B[10][100];

int calc(int x, int y){
    int sum = 0, ds = 0;
    for (int i = x; i < x+s; i++){
        for (int j = y; j < y+t; j++){
            if(B[i][j] != A[i-x][j-y])
                ds++;
            sum += B[i][j];
        }
    }
    if (ds > r)
        return INT_MAX;

    sumM++;
    return sum;
}

int main(){
    cin >> s >> t >> n >> m >> r;

    for (int i = 0; i < s; i++){
        for (int j = 0; j < t; j++){
            cin >> A[i][j];
            sumA += A[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> B[i][j];
        }
    }

    for (int i = 0; i <= n-s; i++){
        for (int j = 0; j <= m-t; j++){
            ans = min(ans, abs(calc(i, j)-sumA));
        }
    }

    cout << sumM << '\n';
    if (sumM)
        cout << ans;
    else
        cout << -1;
}