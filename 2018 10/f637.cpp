#include <bits/stdc++.h>
using namespace std;

string s;
int n, i = -1;
int f(int area){
    i++;
    if (s[i] == '0')
        return 0;

    if (s[i] == '1')
        return area;

    return f(area/4) + f(area/4) + f(area/4) + f(area/4); 
}

int main(){
    cin >> s >> n;
    cout << f(n*n);
}

//my 筆記
//assets/f637.png
//https://www.tldraw.com/r/lURMZhzIbZV-F5qWAoqWj?viewport=0,200,1872,958&page=page:68GJ4sCEtVKk_hs6wcp70
