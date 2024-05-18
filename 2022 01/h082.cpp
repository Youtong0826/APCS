#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct p{
    int atk;
    int df;
    int lives;
    int number;
};

p pl[1005];
vector<p> que;
vector<p> lose;

signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> pl[i].atk;
    
    for(int i = 0; i < n; i++)
        cin >> pl[i].df;

    int s;
    for(int i = 0; i < n; i++){
        cin >> s;
        pl[i].lives = m;
        pl[i].number = i;
        que.push_back(pl[s]);
    }

    while (que.size() != 1){
        for(int i = 0; i < n; i += 2){
            long long ab = que[i].atk * que[i].df;
            long long cd = que[i+1].atk * que[i+1].df;
            if (ab >= cd){
                que[i].atk += cd/(que[i].df*2);
                que[i].df += cd/(que[i].atk*2);
                que[i+1].atk *= 1.5; 
                que[i+1].df *= 1.5; 
                que[i+1].lives--;
                lose.push_back(que[i+1]);
            }
            else{
                que[i+1].atk += ab/(que[i+1].df*2);
                que[i+1].df += ab/(que[i+1].atk*2);
                que[i].atk *= 1.5; 
                que[i].df *= 1.5;
                que[i].lives--;
                lose.push_back(que[i]);
            }
        }

        for (unsigned i = 0; i < lose.size(); i++){
            for (unsigned j = 0; j < que.size(); j++){
                if(lose[i].number == que[j].number)
                    que.erase(que.begin()+i);
            }
        }

        for (unsigned i = 0; i < lose.size(); i++){
            if (lose[i].lives)
                que.push_back(lose[i]);
        }

        lose.clear();
    }
    
    cout << que[0].number+1;
}
