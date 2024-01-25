#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < s.size(); i++){
        if (n == 1 && s[i] >= 'a' && s[i] <= 'z')
            cout << s[i];

        else if (n == 2 && s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];

        else if (n == 3 && s[i] >= '0' && s[i] <= '9')
            cout << s[i];
    }
}