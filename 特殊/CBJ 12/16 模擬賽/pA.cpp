#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> buy;
    int n, nums[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (nums[i] < nums[j]){
                buy.push_back(i);
                break;
            }
        }
    }

    cout << buy.size() << '\n';
    for (int i = 0; i < buy.size(); i++){
        cout << buy[i];
        if (i != buy.size()-1)
            cout << ' ';
    }
}