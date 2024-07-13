#include <bits/stdc++.h>
using namespace std;
#define LL long long

struct p{
    LL atk;
    LL def;
    LL lives;
    LL idx;
};

p pl[1005];
vector<p> que, lose, win;

void beat(int x, int y) {
    LL cd = que[y].atk * que[y].def;
    win.push_back({
        que[x].atk + cd / (que[x].def * 2),
        que[x].def + cd / (que[x].atk * 2),
        que[x].lives,
        que[x].idx
    });

    lose.push_back({
        que[y].atk + que[y].atk / 2,
        que[y].def + que[y].def / 2,
        que[y].lives-1,
        que[y].idx
    });
}

signed main(){
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> pl[i].atk;
     
    for (int i = 1; i <= n; i++)
        cin >> pl[i].def;
 
    for (int i = 0; i < n; i++){
        cin >> s;
        pl[s].lives = m;
        pl[s].idx = s;
        que.push_back(pl[s]);
    }

    while (que.size() != 1){
        for (int i = 1; i < que.size(); i += 2){
            LL ab = que[i-1].atk * que[i-1].def;
            LL cd = que[i].atk * que[i].def;
            if (ab >= cd)
                beat(i-1, i);
            
            else
                beat(i, i-1);
        }

        if (que.size() & 1)
            win.push_back(que.back());
        que.clear();
        
        for (auto x: win)
            que.push_back(x);
        win.clear();

        for (auto x: lose){
            if (x.lives)
                que.push_back(x);
        }
        lose.clear();
    }
    
    cout << que[0].idx;
}
