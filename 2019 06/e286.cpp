#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int length){
    int n = 0;
    for (int i = 0; i < length; i++)
        n += arr[i];
    return n;
}

int main(){
    int a[4], b[4], c = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 4; j++)
            cin >> a[j];
        
        for (int j = 0; j < 4; j++)
            cin >> b[j];

        int x = sum(a, 4), y = sum(b, 4);

        cout << x << ':' << y << '\n';
        c += (x > y)? 1 : (x == y)? 0 : -1;
    }

    if (c > 0)
        cout << "Win";
        
    else if (c < 0)
        cout << "Lose";

    else
        cout << "Tie";
}