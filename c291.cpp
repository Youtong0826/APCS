#include <bits/stdc++.h>
using namespace std;

int n, f[500000], a=0;
bool been[500000]={};

void dfs(int id){
    if (been[f[id]])
        return;
    else{
        been[f[id]] = 1;
        dfs(f[id]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie();
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> f[i];

    for (int i = 0; i < n; i++)
        if(!been[f[i]]){
            a++;
            been[i]=1;
            dfs(f[i]);
        }   

    cout << a;
}