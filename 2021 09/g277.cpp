#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 3e5+1;
struct Node {
    int l, r;
    int lidx, ridx;
    int val;
} seg[maxn*2];

int n, ans = 0, sidx = 1, arr[maxn], pre[maxn];

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    
    if (l == r) 
        seg[idx].val = l;

    else {
        int lidx = seg[idx].lidx = sidx++;
        int ridx = seg[idx].ridx = sidx++;
        int mid = (l+r)/2;
        build(l, mid, lidx);
        build(mid+1, r, ridx);
        seg[idx].val = (arr[seg[lidx].val] < arr[seg[ridx].val])? seg[lidx].val: seg[ridx].val;
    }

    // cout << l << ' ' << r << ' '<< arr[seg[idx].val] << '\n';
}

int query(int l, int r, int idx){
    // cout << l << ' ' << r << ' ' << seg[idx].l << ' ' << seg[idx].r << ' '<< arr[seg[idx].val] << '\n';
    if (seg[idx].l == l && seg[idx].r == r)
        return seg[idx].val;
    
    else {
        int mid = (seg[idx].l+seg[idx].r)/2; // 0 1 0

        if (r <= mid) 
            return query(l, r, seg[idx].lidx);

        else if (l > mid)
            return query(l, r, seg[idx].ridx);
        
        else {
            int lidx = query(l, mid, seg[idx].lidx), ridx = query(mid+1, r, seg[idx].ridx);
            return (arr[lidx] < arr[ridx])? lidx: ridx;
        }
    }
}

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = arr[i] + pre[i-1];
    }

    build(1, n, 0);
    int l = 1, r = n;
    while (l != r){
        int m = query(l, r, 0);
        int lsum = pre[m-1]-pre[l-1], rsum = pre[r]-pre[m];
        // cout << l << ' ' << r << ' ' << m << ' ' << lsum << ' ' << rsum << '\n';
        if (lsum > rsum) 
            r = m-1;
        
        else 
            l = m+1;
        
    }

    cout << arr[l];
}