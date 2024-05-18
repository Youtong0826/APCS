#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[7], b[7];

    cin >> n;
    while (n--){
        int f = 1;
        
        for(int i = 0; i < 7; i++)
            cin >> a[i];

        for(int i = 0; i < 7; i++)
            cin >> b[i];
        
        if(!(a[1] != a[3] && a[1] == a[5] && b[1] != b[3] && b[1] == b[5])){
            cout << 'A';
            f = 0;
        }

        if(!(a[6] == 1 && b[6] == 0)){
            cout << 'B';
            f = 0;
        }

        if(!(a[1] != b[1] && a[3] != b[3] && a[5] != b[5])){
            cout << 'C';
            f = 0;
        }

        if(f)
            cout << "None";

        cout << '\n';
    }
}