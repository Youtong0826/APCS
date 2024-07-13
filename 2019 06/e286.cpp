#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0, x, y, t;
    for (int i = 0; i < 2; i++) {
        x = 0, y = 0;

        for (int j = 0; j < 4; j++) {
            cin >> t;
            x += t;
        }

        for (int j = 0; j < 4; j++) {
            cin >> t;
            y += t;
        }

        if (x > y) 
            a++;

        else if (x < y) 
            b++;

        cout << x << ':' << y << '\n'; 
    }
    
    if (a > b)
        cout << "Win";

    else if (a < b)
        cout << "Lose";

    else
        cout << "Tie";
}
 