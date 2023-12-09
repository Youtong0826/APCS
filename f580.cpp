#include <bits/stdc++.h>
using namespace std;

struct dice{
    int top;
    int down;
    int front;
    int back;
    int left;
    int right;
};

vector<dice> dices (21, {1, 6, 4, 3, 5, 2});

void turn_front(int i){
    dice &x = dices[i];
    x = {x.back, x.front, x.top, x.down, x.left, x.right};
}

void turn_right(int i){
    dice &x = dices[i];
    x = {x.left, x.right, x.front, x.back, x.down, x.top};
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    while(m--){
        cin >> a >> b;
        if(b > 0){
            swap(dices[a], dices[b]);
        }
        else if (b == -1)
            turn_front(a);

        else
            turn_right(a);
    }

    for (int i = 1; i <= n; i++)
        cout << dices[i].top << ' ';
}