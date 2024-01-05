#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int a, s, pre[11];

    for (int i = 0; i < 10 ; i++){
        nums.push_back(i);
    }

    // pre[0] = 0;
    // for (int i = 1; i < 11; i++){
    //     pre[i] = nums[i-1] + pre[i-1];
    // }

    cin >> s;

    for (int i = 0; i < nums.size(); i++){
        int x = nums[i];
        for (int j = 0; j < nums.size(); j++){
            x += nums[j]
        }
    }

}