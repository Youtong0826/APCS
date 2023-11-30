#include <bits/stdc++.h>
using namespace std;

int main(){
    int f, n, y, i, r = -1;
    cin >> f >> n;
    for (i = 1; i <= n; i++){
        r = y;
        cin >> y;
        
        cout << f << ' ';
        if((f < y || (f == 5 && y == 0)) && !(f == 0 && y == 5)){
            cout <<  ": Won at round " << i;
            return 0;
        }

        else if (f > y || (f == 0 && y == 5)){
            cout << ": Lost at round " << i;
            return 0;
        }

        else{
            if (y == r){
                if (r == 0)
                    f = 5;

                else if (r == 2)
                    f = 0;
                
                else
                    f = 2;      
            }
            else
                f = y;
        }
    }

    cout << ": Drew at round " << i-1;
}