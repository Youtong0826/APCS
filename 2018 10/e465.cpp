#include <iostream>
#include <cstring>
using namespace std;

int dp[2][200005];

// 在 範圍 S 裡面找"大於但不超過"
// 換句話說就是在 M - S 的空間裡面找最大　
// 之後再用 "已租出去的空間和" - S 就可以得出損失值了

long long readint()
{
    long long a = 0;
    char c = '0';
    while (c >= '0' && c <= '9')
    {
        a = (a << 3) + (a << 1) + c - '0';
        c = getchar();
    }
    return a;
}

void writeint(long long d)
{
    if (d == 0)
    {
        putchar(48);
        return;
    }
    int len = 0;
    char n[20];
    while (d > 0)
    {
        n[len] = d % 10 + 48;
        len++;
        d /= 10;
    }
    for (int i = len - 1; i >= 0; i--)
        putchar(n[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m(readint()), s(readint()), n(readint()), x, sum = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        x = readint(), sum += x, idx = i & 1;
        for (int j = 0; j <= m - s; j++) {
            dp[idx ^ 1][j] = dp[idx][j];
            if (x <= j) 
                dp[idx ^ 1][j] = max(dp[idx][j], dp[idx][j - x] + x);
        }
    }
    
    writeint(sum - dp[idx ^ 1][m-s]);
}