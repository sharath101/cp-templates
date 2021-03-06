#include <bits/stdc++.h>
     
using namespace std;
 
//1 indexed    
const int maxn = 1e5, maxk = 1e6 + 1;
int root[16*maxn], L[16 * maxn], R[16 * maxn], sum[16 * maxn];
int rt = 1, sz = 1;
int lpos[maxk];
     
int copy(int v, int &u){
    L[sz] = L[v];
    R[sz] = R[v];
    sum[sz] = sum[v];
    return u = sz++;
}
     
void make_root(){
    copy(root[rt - 1], root[rt]);
    rt++;
}
     
void add(int pos, int x, int v = root[rt - 1], int l = 0, int r = maxn){
 	sum[v] += x;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(pos < m)
        add(pos, x, copy(L[v], L[v]), l, m);
    else
        add(pos, x, copy(R[v], R[v]), m, r);
}
     
int get(int a, int b, int v, int l = 0, int r = maxn){
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r);
}
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        make_root();
        add(lpos[t], -1);
        lpos[t] = i;
        add(lpos[t], 1);
    }
     
    int q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << get(l, r + 1, root[r]) << "\n";
    }
    return 0;
}
     
