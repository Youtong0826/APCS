#include <bits/stdc++.h>
using namespace std;

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

long long sum = 0;

void dfs(int last){
    int n(readint());
    if (!n)
        return;

    if (last)
        sum += abs(n-last);
    
    if (n & 1){
        dfs(n);
        dfs(n);
        dfs(n);
    }
    
    else {
        dfs(n);
        dfs(n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dfs(0);
    writeint(sum);
}